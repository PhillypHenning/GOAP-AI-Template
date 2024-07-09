# Goal-Oriented Action Planning (GOAP) AI Template in C++

## Overview

This project provides a basic template for implementing Goal-Oriented Action Planning (GOAP) Artificial Intelligence (AI) in C++. GOAP is an AI decision-making technique primarily used in game development to create more believable and complex behaviors for non-player characters (NPCs).

This template includes:
- **Class for Actions (`Action.h` and `Action.cpp`)**
- **Simple Planner (`Planner.h` and `Planner.cpp`)**
- **Main Program to Test (`main.cpp`)**

## Structure

- `Action.h`: Defines the `Action` class that encapsulates actions with preconditions, effects, and costs.
- `Action.cpp`: Implements the methods defined in `Action.h`.
- `Planner.h`: Defines the `Planner` class which plans a sequence of actions to achieve a goal.
- `Planner.cpp`: Implements the planning algorithm using a heuristic-based approach.
- `main.cpp`: Contains the main function demonstrating a simple example with actions and a goal.

## Dependencies

- **Compiler**: `clang++` (included with Xcode Command Line Tools on macOS)

## Building the Project

1. **Clone the Repository**

   If you haven't already, clone the repository to your local machine:
   ```bash
   git clone [repository_url]
   cd path/to/your/goap/directory
   ```

2. **Compile the Program**

   Use the following command to compile the program:
   ```bash
   clang++ -std=c++11 main.cpp Action.cpp Planner.cpp -o goap
   ```

## Running the Program

After compiling, run the executable:
```bash
./goap
```

## Expected Output

The expected output for this example is to display the sequence of actions that the planner generates to achieve the goal. For the provided scenario, output should include actions like finding an axe, gathering wood, and building a house:

```
Initial World State:
hasAxe = 0
hasHouse = 0
hasWood = 0
Goal State:
hasHouse = 1
Filtering actions based on current world state
Not available: Gather Wood
Not available: Build House
Available: Find Axe
Selected Action: Find Axe with cost 2
Effect applied: hasAxe = 1
Filtering actions based on current world state
Available: Gather Wood
Not available: Build House
Available: Find Axe
Selected Action: Gather Wood with cost 1
Effect applied: hasWood = 1
Filtering actions based on current world state
Available: Gather Wood
Available: Build House
Available: Find Axe
Selected Action: Build House with cost 5
Effect applied: hasHouse = 1
Goal reached!
Action Plan:
Find Axe
Gather Wood
Build House
```

## Customization

You can customize the actions, initial world state, and the goal in the `main.cpp` file. Add more actions and world states to create more complex scenarios and test the planner's capabilities.

### License

This project is open-source and available under the MIT license.

## Contributing

Contributions are welcome! Feel free to submit issues, fork the repository, and submit pull requests.

## Contact

For questions or suggestions, please open an issue or contact [Your Name] at [Your Email].

---

This README should provide sufficient guidance to understand, build, and run the GOAP AI template. Feel free to adapt and expand it to better fit your needs!# GOAP-AI-Template
