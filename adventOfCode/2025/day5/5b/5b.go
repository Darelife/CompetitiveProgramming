package main

import (
	"bufio"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	solve()
}

func solve() {
	in := bufio.NewScanner(os.Stdin)
	in.Buffer(make([]byte, 0, 1024*1024), 1024*1024*1024)

	diff := make(map[int]int)

	for {
		if !in.Scan() {
			break
		}

		line := in.Text()
		if strings.TrimSpace(line) == "" {
			break
		}

		parts := strings.Split(line, "-")

		if len(parts) != 2 {
			continue
		}

		l, _ := strconv.Atoi(parts[0])
		r, _ := strconv.Atoi(parts[1])

		diff[l]++
		diff[r+1]--
	}

	var ids []int
	for in.Scan() {
		s := strings.TrimSpace(in.Text())
		if s == "" {
			continue
		}
		x, _ := strconv.Atoi(s)
		ids = append(ids, x)
	}

	sort.Ints(ids)

	keys := []int{}
	for k := range diff {
		keys = append(keys, k)
	}
	sort.Ints(keys)

	var merged [][2]int
	pre := 0
	l := -1

	for _, k := range keys {
		pre += diff[k]
		if pre-diff[k] == 0 && pre > 0 {
			l = k
		}
		if pre-diff[k] > 0 && pre == 0 {
			merged = append(merged, [2]int{l, k - 1})
		}
	}

	ans := 0
	// i := 0

	for _, rng := range merged {
		ans += rng[1] - rng[0] + 1
	}

	println(ans)
}
