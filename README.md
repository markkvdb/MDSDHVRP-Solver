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

The first line 

```txt
2 2 30
```

specifies the number of different vehicles, depots and customers, respectively. The second part

```txt
   0   200     8    80    25
   1    50     8   110    10
```

defines the vehicle number, 