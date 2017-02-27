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


### Customer
Data members:
- Demand
- Supplied
- List of routes
- Position in routes

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
        - `cheapestInsertion(customerList)`
        
`cheapestInsertion(customerList)`
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

## Stopping criteria