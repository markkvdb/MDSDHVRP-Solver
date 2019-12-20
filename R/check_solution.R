instanceList <- 1:2
splitsRatio <- objectives <- meanDemand <- maxDemand <- minDemand <- invDemandRatio <- noVehicles <- rep(NA, length(instanceList))

emptyVehicles <- rep(0,length(instanceList))
demandOk = 0

RTOs <- rep(NA, length(instanceList))

for (i in instanceList){
  rto <- 0
  
  
  
  inputFile <- paste("instanceB_",i,"_input.txt",sep = "")
  outputFile <- paste("instanceB_",i,"_output.txt",sep = "")
  #outputFile <- "outputtje.txt"
  setwd("C:/Users/Niels/CLionProjects/ORACS/src/data/")
  input <- scan(inputFile,quiet = T)
  no_vehicleTypes <- as.integer(input[1])
  no_depots <- as.integer(input[2])
  no_customers <- as.integer(input[3])
  
  vehiclePoints <- no_vehicleTypes * 5 
  depotPoints <- no_depots* (4 + no_vehicleTypes)
  
  vehicle_data <- input[4:(vehiclePoints+ 3)]
  depot_data <- input[(vehiclePoints + 4):(vehiclePoints + 3 + depotPoints)]
  customer_data <- input[(vehiclePoints + 4 + depotPoints):length(input)]
  
  
  v_data <- matrix(vehicle_data,ncol = 5,byrow = T)
  no_vehicleTypes <- nrow(v_data)
  d_data <- matrix(depot_data,ncol = (4 + no_vehicleTypes), byrow = T)
  totalCap <- as.matrix(d_data[,5:(4 + no_vehicleTypes)]) %*% as.matrix(v_data[,2])
  inv.prime <- pmin(d_data[,4],totalCap)
  totalInv <- sum(inv.prime)
  
  
  c_data<-matrix(customer_data,ncol = 5 ,byrow = T)
  totalDemand <- sum(c_data[,4])
  meanDemand[i] <- mean(c_data[,4])
  maxDemand[i] <- max(c_data[,4])
  minDemand[i] <- min(c_data[,4])
  
  invDemandRatio[i] <- totalDemand / totalInv
  
  nodes <- c_data[,2:3]
  nodes2 <- d_data[,2:3]
  
  allNodes <- rbind(nodes,nodes2)
  distance_matrix <- as.matrix(dist(allNodes))
  
  no_depots <- nrow(d_data)
  no_customers <- nrow(c_data)
  no_vehicleTypes <- nrow(v_data)
  
  eta <- matrix(0,no_depots,no_vehicleTypes)
  delivered <- visits <- rep(0,no_customers)
  
  
  setwd("C:/Users/Niels/Desktop/M4solutions") 
  
  con  <- file(outputFile, open = "r")
  
  results.list <- list();
  current.line <- 1
  while (length(line <- readLines(con, n = 1, warn = FALSE)) > 0) {
    results.list[[current.line]] <- as.double(unlist(strsplit(line, split=" ")))
    current.line <- current.line + 1
  } 
  close(con)
  
  V <- length(results.list) # number of vehicles + 2
  noVehicles[i] <- V - 2
  solution <- vector("list",V)
  inventories <- rep(0,no_depots)
  routes <- vector("list",V)
  quantities <- rep(0,V)
  routeCosts <- rep(0,V)
  routeDurations <- rep(0,V)
  travelDistances <- rep(NA,V)
  
  totalOutputCost <- results.list[[1]][1]
  
  totalCost = 0
  
  for (j in 3:V){
    line <- results.list[[j]]
    lList <- length(line)
    
    depot <- line[1] 
    vehicleType <- line[2] 
    depot_idx <- depot + 1
    depot_idx2 <- depot_idx + no_customers
    vehicleType_idx <- vehicleType + 1
    eta[depot_idx,vehicleType_idx] <- eta[depot_idx, vehicleType_idx] + 1
    if (eta[depot_idx,vehicleType_idx] > d_data[depot_idx, (4 + vehicleType_idx)]){
      cat("Too many vehicles of type ", vehicleType, " at depot ", depot)
      cat("!!", j, "!!")
    }
    
    
    if (lList > 8){
      
      route <- as.integer(line[seq(9,lList,2)]) + 1
      deliveries <- line[seq(10,lList,2)]
      for (k in 1:length(route)){
        customer <- route[k]
        delivered[customer] <- delivered[customer] + deliveries[k]
        visits[customer] <- visits[customer] + 1
      }
      
      
      quantity <- sum(deliveries)
      quantities[j] <- quantity
      inventories[depot_idx] = inventories[depot_idx] + quantity
      
      if(quantity != line[5]){
        cat("Wrong quantity for vehicle type ", vehicleType, " at depot ", depot)
      }
      
      if(quantity > v_data[vehicleType_idx,2]){
        print("infeasible w.r.t. capacity")
      }
      
      serviceTime <- sum(c_data[route,5])
      if(serviceTime != line[6]){
        
        #print("customer service time incorrect")
        #cat("at depot  ", depot, " and type ", vehicleType)
        #print(j)
        
        
        #cat("line[6] ", line[6], " serviceTime ", serviceTime)
      }
      
      travelDistance = 0
      lengthRoute <- length(route)
      if(lengthRoute > 1){
        
        for(idx in 1:(lengthRoute - 1)){
          from = route[idx]
          to = route[idx + 1]
          travelDistance = travelDistance + distance_matrix[from,to]
          
          
          
        }
      }  
      
      
      
      travelDistance = travelDistance + distance_matrix[depot_idx2,route[1]] + distance_matrix[depot_idx2,route[lengthRoute]]
      travelDistances[j] = travelDistance
      routeCost = travelDistance * v_data[vehicleType_idx,5]
      routeCosts[j] = routeCost
      
      
      
      travelTime <- travelDistance / v_data[vehicleType_idx,4]
      
      routeDuration <- travelTime + serviceTime
      routeDurations[j] = routeDuration
      
      if(routeDuration > v_data[vehicleType_idx,3]){
        print("Infeasible wrt travel time")
        rto <- rto + routeDuration - v_data[vehicleType_idx,3]
      }
      
    }
    
    route <- c(depot_idx2,route,depot_idx2)
    routes[[j]] <- route
    route <- NULL
    
    if (lList == 8){
      emptyVehicles[i] <- emptyVehicles[i] + 1
      quantities[j] = 0
      routeDurations[j] = 0
      routeCosts[j] = 0
      travelDistances[j] = 0
    }
    
  }
  
  
  if(!all(inventories <= d_data[,4])){
    print("Inventories are NOT ok")
  }
  
  if(!all(eta == d_data[,5:(4 + no_vehicleTypes)])){
    print("Vehicles are NOT ok")
  }
  
  
  if(!all(delivered == c_data[,4])){
    print("demands are NOT satisfied")
  }else{
    demandOk = demandOk + 1
  }
  
  
  for(k in 3:V){
    if(length(unique(routes[[k]])) != length(routes[[k]]) - 1){
      print(routes[[k]])
      print("customer featured twice on same route")
    }
  }
  
  totalCost = sum(routeCosts)
  #objectives[i / 50] <- totalCost
  #cat("Total cost ", totalCost )
  #cat("Total cost according to output ", totalOutputCost)
  splitsRatio[i] <- sum(visits)/no_customers - 1
  
  
  
  
}



plotRoute <- function(route,col){
  routeLength <- length(route) - 1
  for (i in 1:routeLength){
    idx1 <- route[i]
    idx2 <- route[i+1]
    node1 <- allNodes[idx1,]
    node2 <- allNodes[idx2,]
    segments(node1[1],node1[2],node2[1],node2[2],col = col,lwd = 2)
  }
  
}
# 
# plot(nodes[,1],nodes[,2],xlab= "",ylab = "",cex = 1, pch = 16)
# points(nodes2[,1],nodes2[,2],pch = 15,cex = 1.5)
# 
# for(i in 3:V){
#   myRoute <- routes[[i]]
#   plotRoute(myRoute,col = i - 2)
# }

# for(i in 3:V){
#   plot(nodes[,1],nodes[,2],xlab= "",ylab = "",cex = 1, pch = 16)
#   points(nodes2[,1],nodes2[,2],pch = 15,cex = 1.5)
# 
#   myRoute <- routes[[i]]
#   plotRoute(myRoute,col = i - 2)
# }

# 
# tights <- which(invDemandRatio > 0.9)
# nonTights <- which(invDemandRatio < 1)
# smallDemand <- which(meanDemand <= 20)
# largeDemand <- which(meanDemand > 20)
# 
# 
# 
# plot(meanDemand,splitsRatio, pch = 4 ,bty ="n",xlab = "Mean demand size", ylab = "Average number of splits per customer")
# plot(invDemandRatio[tights],splitsRatio[tights], pch = 4 ,bty ="n",xlab = "Total demand to inventory ratio", ylab = "Average number of splits per customer")
# plot(invDemandRatio,splitsRatio, pch = 4 ,bty ="n",xlab = "Demand to inventory ratio", ylab = "Average number of splits per customer")
