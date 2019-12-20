# MDSDHVRP-I Solver

This library provides a solver for the the multi-depot split-delivery vehicle routing problem with inventory constraints and heterogeneous fleet prolbem.

## Overview

We apply a metaheuristic search techniques to an extension of the multi-depot vehicle routing problem. The goal of this research is to design an efficient solution approach that finds high-quality feasible solutions for the multi-depot split-delivery vehicle routing problem with inventory constraints and heterogeneous fleet. We use an extended large neighbour search algorithm, which combines destroy and repair operators with local search techniques. Our algorithm finds feasible solutions for a large number of instances in short time. The main contributions of this paper are twofold: we extend and apply an existing metaheuristic approach, and we consider a new extension of the vehicle routing problem.

A link with performance details and an overview of the operators can be found [here](MDSDHVRP-I.pdf).

## Installation

Building the solver requires a recent version of `cmake` and a C++ compiler that supports the 2011 standard. After, `cmake` can be configured by running

```bash
cmake -DCMAKE_BUILD_TYPE=Release -B build
```

The program can now be built as

```bash
cmake --build build --config Release --target all -- -j 10
```

## Usage

### Input file 

Now that we have build our solver we can use by providing a file with our problem instance. The input file should be defined according to the following scheme

```txt
2 2 30

   0   200     8    80    25
   1    50     8   110    10

   0   57.84   50.38  203    1    1
   1  -84.84  -39.79  160    5    1

   0  -64.35  -90.76    8  0.05
   1    6.77  -84.59    5  0.09
   2  -58.57   14.63   15  0.04
   3   59.16   89.24    5  0.09
   4   46.49   77.78   23  0.08
   5   55.12   81.50   19  0.05
   6   59.28   89.63    4  0.09
   7   51.71   54.42   24  0.06
   8   10.22   56.17   21  0.07
   9   27.20  -83.00   19  0.09
  10  -20.87   63.39    5  0.07
  11    3.21  -68.39    4  0.03
  12   27.90  -61.73    1  0.03
  13   63.60  -25.71   15  0.03
  14   32.38  -49.92    8  0.04
  15   23.90  -75.21   13  0.02
  16  -94.52   39.39   23  0.02
  17  -97.87  -47.92    8  0.06
  18  -73.88  -47.22    7  0.05
  19  -86.10    5.76   17  0.04
  20  -69.45    5.35    5  0.05
  21   -9.02   95.03    4  0.02
  22    0.87   -7.88   24  0.09
  23  -97.95   29.66   15  0.03
  24  -78.38  -14.60    4  0.02
  25  -19.18  -66.77    6  0.07
  26  -13.62  -76.94    7  0.01
  27  -47.75  -26.75    2  0.04
  28  -55.08  -20.71    1  0.01
  29   46.03  -22.40    1  0.02
```

The first line specifies the number of different vehicles, depots and customers, respectively.

```txt
2 2 30
```

 The second part defines the vehicle number, capacity, maximum duration of trip, speed and cost per unit of distance.

```txt
   0   200     8    80    25
   1    50     8   110    10
```

The third part defines the depot id, x-coordinate, y-coordinate, total capacity of items, number of vehicles of type 1 and the number of vehicles of type 2.

```txt
   0   57.84   50.38  203    1    1
   1  -84.84  -39.79  160    5    1
```

Note that if we have more vehicle types, then the lines above will be extended as needed. The last part concerns the customers. The numbers on the rows are: id, x-coordinate, y-coordinate, items demanded and the processing time.

```txt
   0  -64.35  -90.76    8  0.05
   1    6.77  -84.59    5  0.09
   2  -58.57   14.63   15  0.04
   3   59.16   89.24    5  0.09
   4   46.49   77.78   23  0.08
   5   55.12   81.50   19  0.05
   6   59.28   89.63    4  0.09
   7   51.71   54.42   24  0.06
   8   10.22   56.17   21  0.07
   9   27.20  -83.00   19  0.09
  10  -20.87   63.39    5  0.07
  11    3.21  -68.39    4  0.03
  12   27.90  -61.73    1  0.03
  13   63.60  -25.71   15  0.03
  14   32.38  -49.92    8  0.04
  15   23.90  -75.21   13  0.02
  16  -94.52   39.39   23  0.02
  17  -97.87  -47.92    8  0.06
  18  -73.88  -47.22    7  0.05
  19  -86.10    5.76   17  0.04
  20  -69.45    5.35    5  0.05
  21   -9.02   95.03    4  0.02
  22    0.87   -7.88   24  0.09
  23  -97.95   29.66   15  0.03
  24  -78.38  -14.60    4  0.02
  25  -19.18  -66.77    6  0.07
  26  -13.62  -76.94    7  0.01
  27  -47.75  -26.75    2  0.04
  28  -55.08  -20.71    1  0.01
  29   46.03  -22.40    1  0.02
```

Example input files can be found in the `src/data` folder.

### Obtaining solution

Obtaining a solution can be done by providing an input file as described above as

```bash
build/ORACS <Input file>
```

where `<Input file>` is replaced by the location of the input file according to the style as described in the same folder as the input file.

### Output file

The output file of the input file in the example looks as follows

```txt
58119.35

0 0     595.22  14880.60 103  0.55  7.44  7.99  0 8 1 5 2 15 3 5 4 23 5 19 6 4 7 24
0 1     617.83   6178.27  50  0.29  5.62  5.91  8 21 9 19 10 5 11 4 12 1
1 0     610.17  15254.28  96  0.31  7.63  7.94  13 15 14 8 15 13 16 23 17 8 18 7 19 17 20 5
1 0     608.21  15205.18  63  0.29  7.60  7.89  21 4 22 24 23 15 24 4 25 6 26 7 27 2 28 1
1 0     264.04   6601.02   1  0.02  3.30  3.32  29 1
1 0       0.00      0.00   0  0.00  0.00  0.00  
1 0       0.00      0.00   0  0.00  0.00  0.00  
1 1       0.00      0.00   0  0.00  0.00  0.00  
```

The first lines gives the total objective function which is the sum of the cost of all trips by the vehicles while satisfying all demand. The following lines have the following structure

```txt
<depot id> <vehicle type> <...> <...> <total quantity> <service time> <travel time> <total time> <customer id 1> <quantity customer id 1> <customer id 2> <quantity customer id 2> <...>
```

### Visualise solution

TODO