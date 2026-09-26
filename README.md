# Codeforces
This is a repo containing all of my codeforce problems <br>
Codeforce Id : [Darelife](https://codeforces.com/profile/Darelife)


## Diary
- [The Diary](./diary.md)


# Local CPH-style runner

## Receive problems from Competitive Companion

In Zed, run the task **Start Competitive Companion receiver** using `task: spawn`. It starts the receiver in the background for this Zed workspace only. The task is defined in `.zed/tasks.json`.

To run it manually from a terminal instead:

```bash
./cpserve
```

Configure the Competitive Companion browser extension to send to:

```text
http://127.0.0.1:10043
```

When you press the extension's **Send to Competitive Companion** button, the receiver creates an empty solution file if needed, saves the problem and its testcases into the matching `.cph/` directory, and opens the solution in Zed automatically. `cpstart` is safe to run repeatedly; it will not start duplicate receivers.

Then run the received solution with your shortcut or:

```bash
./cprun Problems/your_solution.cpp
```


The repository keeps testcases in the CPH files under `.cph/`; `cp.py` reads those files directly and does not create a separate testcase directory.

```bash
# Run every testcase for a solution
./cprun Problems/A_1_D_Eraser.cpp

# Run only testcase 2
./cprun Problems/A_1_D_Eraser.cpp --case 2
```

The runner compiles with `g++ -std=c++17 -O2`, compares whitespace-separated output like competitive-programming judges, and prints a compact colored `AC`/`WA`/`TLE`/`RTE` summary. On a failed case it shows the input, expected output, and received output. (`run` is optional; the source path is the only required argument.) The executable launcher is `cprun`; it requires Python 3 and `g++` to be installed.

# Explanation
- Starting from 25 June 2024, I will try to explain the code of all the qs i solve in markdown

1. [C_Boring_Day](./Problems/C_Boring_Day.cpp) - [Explanation](./explanation/C_Boring_Day.md)
2. [E_Cells_Arrangement](./Problems/E_Cells_Arrangement.cpp) - [Explanation](./explanation/E_Cells_Arrangement.md)
3. [B_Charming_Meals](./Problems/B_Charming_Meals.cpp) - [Explanation](./explanation/B_Charming_Meals.md)
4. [C_Mad_MAD_Sum.cpp](./Problems/C_Mad_MAD_Sum.cpp) - [Explanation](./explanation/C_Mad_MAD_Sum.md)
5. [C_Given_Length_and_Sum_of_Digits.cpp](./Problems/C_Given_Length_and_Sum_of_Digits.cpp) - [Explanation](./explanation/C_Given_Length_and_Sum_of_Digits.md)