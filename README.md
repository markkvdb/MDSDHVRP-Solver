# ORACS

## Data structure
Depot-vehicle combination:
- Route
- Deliver quantities
- Total deliver quantity
- Route cost
- Travel time

Customer:
- Total deliver quantity
- List of routes with:
    - Depot
    - Vehicle type
    - Route index
    - Deliver quantity
    
## Classes
### Depot
Data members:
- List of vehicles
- Leftover inventory

Functions:

### Vehicle
Data members:
- Type
- Route
- Leftover capacity
- Leftover travel time

Functions:
- Route cost

### Route
Data members: 
- Ordered list of customers (index)
- Delivery quantity
- Total delivery quantity
- Service time
- Travel distance

Functions:


### Customer (TODO)
Data members:
- Demand
- Total delivery quantity
- Depot

## Initialisation

### Load data
Load `m`, the number of depots. Load `K`, the number of vehicles types. Load `n`, the number of customers.

Load distance matrix `distanceMatrix` into Matrix datatype with dimensions (n + m) x (n + m).
Create depot matrix `depotMatrix` with dimensions m x (K + 1).
Load customer matrix `customerMatrix` with dimension n x 2.
Load vehicle matrix `vehicleMatrix` with dimension K x 4

### Create empty solution
For each depot (m depots):
- Select row from `depotMatrix`
- Set inventory by calling `Solution::addDepot(I_j)`
- For each vehicle type:
    - Add `n_jk` vehicles by calling `Depot::addVehicle(k)` function

For each customer in `customerMatrix`:
- Create customer by calling `Solution::addCustomer(demand, servicetime)`

### Construct initial solution
1. Sort `customerMatrix` on ascending demand.
2. Create `depotCustomerAllocation` (is a `vector<vector<int>>`). Create `depotCustomerDemand`.
3. Loop over `customerMatrix`:
    - Create `leftoverDemand = customer.getDemand()`.
    - While `leftoverDemand > 0`
        - Find smallest distance to depots, say `smallDepot`.
        - Add customer.
    - end
    
4. Loop over depot (m depots):
    - Sort vehicles based on costs.
    - Create `customerList` and `customerDropOff`.
    - Loop over sorted vehicle list:
        - Create `leftoverCapacity = vehicle.getCapacity()`
        - while (`leftoverCapacity > 0`) do 
            - Take new customer from `depotCustomerAllocation` (first time random).
            - Add customer to `customerList` and `customerDropOff`.
            - Update `leftoverCapacity`.
            - if (`leftoverCapacity >= demand`) then
                - Delete from `depotCustomerAllocation`.
            - else update `depotCustomerDemand`.
        - end
        - `route = cheapestInsertion(customerList)`
        - `vehicle.setRoute(route, deliverQuantities)`
        - `Customers.addRoute(route, deliverQuantities)`
        
        
#### cheapestInsertion(customerList) #####
1. Create `route = {0, 0};`
2. While customerList is not empty
    - For each customer in customerList
        - For each insertion option (N - 1):
            - Check if minimum
    - Update route by inserting cheapest.
    - Remove customer from customerList.
3. Ready to rambo.


## Local search techniques

## Perturbation

Three destroy operators (remove q customers) + 1 repair operator (reinserts customers).

### randomRemoval(solution) ###
1. Select seed customer from customer list. Store in toBeRemoved.
2. Find q-1 nearest customers. Store in toBeRemoved.
3. removeCustomers(solution, toBeRemoved) (see below)

### removeCustomers(solution, toBeRemoved)
1. For each customer in toBeRemoved:
    - For each vehicle of customer:
        - Find place customer in route
        - Remove customer from route (and dropoff)
        - Update load, length, serviceTime, route cost
        - Remove depot+vehicle_id from customer
2. toBeReinserted = toBeRemoved (for later use)
2. Return destroyed solution and toBeReinserted

### costRemoval(solution) ###
1. For customers 1,...,n:
   - computeRemovalGain(solution, customer) (see below)
   - store result in vector gains, along with customer_id (gains = [[1,gain_1],...,[n,gain_n]])
2. Find q largest gains, store corresponding customer_ids in toBeRemoved
3. removeCustomers(solution, toBeRemoved)

### computeRemovalGain(solution, customer) ###
1.  For each vehicle of customer, compute vehicleRemovalGain:
        - Find place in route
        - Distance gain: Use distanceMatrix (multiply by alpha)
        - Feasibility gain (only if route is infeasible in the first place):
            - Find old and new travel duration (travel time + service time)
            - Use arithmetic.
        - vehicleRemovalGain = distance gain + feasibility gain
    - totalRemovalGain = sum(vehicleRemovalGain)
    - totalRemovalGain = totalRemovalGain * uniform(a, b) (a = 0.8, b = 1.2)(RNG).
2. return totalRemovalGain

### routeRemoval(solution) ###
1. Pick random non-empty vehicle.
2. Find corresponding route
3. Store at random min(q, route.length()) customers in toBeRemoved
4. removeCustomers(solution, toBeRemoved)

### reinsert(solution, toBeReinserted) ###
1. demand = demand(toBeReinserted)
2. While toBeReinserted is not empty
    - Select random customer from toBeReinserted.
    - minInsertion = Infinity
    - depot = -1, vehicle = -1, idx = -1 (initilize insertion location)
    - For each vehicle
        - For each insertion option
            - Find insertionCost:
                - Additional travel costs
                - Infeasibility penalties
            - If (insertion costs < minInsertion)
                - minInsertion = insertionCost
                - update: depot, vehicle, and idx
    - Insert customer at depot, vehicle, idx:
    - If (insufficient inventory/capacity)
        - Allocate as much as possible and split demand
        - Update demand
    - If (sufficient inventory and capacity)
        - Allocate all demand
        - remove customer from toBeReinserted
3. Return solution
Note: we can alternatively check in advance for sufficient inventory/capacity, and discard the insertion option
if insufficient. One problem is that all insertion options may be discarded (a simple workaround is to repeat the
search, now allowing for splits).
I suggest moving this to the tuning phase (if it turns out that too many splits are generated,
this is one place where we can look.)


### algorithm structure ###



solutions: best_feasible, best_solution, s, s_prime
f(solution) = cost(solution) + penalty(solution)

cost(solution) = sum(travelCosts)
penalty(solution) = penalty*travelTimeViolation(solution)
penalty is a parameter between iota_min and iota_max = iota_min*delta^100 (or delta^10, whatever)
multiplied by factor delta if solution is infeasible



initialize:
penalty = iota_min (global)
s = initialSolution()
best_solution = s

if(s is feasible){
    best_feasible = s
} else
{
    best_feasible = empty (objective value: inf)
}

T = r*f(s) (0 < r < 1) (Temperature for simulated annealing)

iter == 1
repeat
    s_prime = DestroyAndRepair(s)

    if (f(s_prime) < (1 + theta)*f(best_solution))
    {
        for (routine in routineList) # routineList has 8 routines
        {
            s_prime = routine(s_prime) : best improvement

            if (improvement)
            {
                return to first routine (that is, reenter for-loop) #this is rather extensive,
                # an alternative is to move to the next routine if the current routine does not yield
                # further improvements
            }

        }
    }

    best_solution =  min(s_prime, best_solution) #compare objectives, use same global penalty parameter

    if(s_prime is feasible)
    {
        best_feasible = min(s_prime, best_feasible) #compare objectives
    }

    simulatedAnnealing(s_prime, s) (simulatedAnnealing: see below)

    updatePenalty(s)

    iter++
until iter == max_iter or comp_time > max_comp_time


### updatePenalty(solution) ###

if(solution is not feasible)
{
    penalty = min(iota_max, iota * delta)
}
else
{
    penalty = max(iota_min, iota / delta)
}

### simulatedAnnealing(s1, s2) ###

if(f(s1) <= f(s2))
{
    T = r*f(s1) (0<r<1)
    return s1
}

if(f(s1) > f(s2))
{
    diff = f(s1) - f(s)
    return s1 with probability exp(-diff/T)
    T = max(r*T, T_min) (0 < r <1, T_min is minimum temperature)
}




