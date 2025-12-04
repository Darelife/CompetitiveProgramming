package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	grid:=[]string{}

	for scanner.Scan() {
		line := scanner.Text();
		if line != "" {
			grid = append(grid, line);
		}
	}

	var n int = len(grid)
	var m int = len(grid[0])

	var ans int = 0;

	dirs := [][]int{
		{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1},
	}

	for i:=0; i<n; i++ {
		for j:=0; j<m; j++ {
			if (grid[i][j] != '@')  {
				continue
			}
			cnt := 0
			for _,d := range dirs {
				ni := i+d[0]
				nj := j+d[1]

				if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '@') {cnt++}
			}

			if cnt < 4 {
				ans++
			}
		}
	}

	fmt.Println(ans)
}

func main() {
	solve()
}
