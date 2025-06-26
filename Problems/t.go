package main

import (
	"fmt"
	"net/http"
	"time"
)

func main() {
	for {
		url := "https://codeforces.com"
		cli := http.Client{Timeout: 10 * time.Second}
		res, _ := cli.Get(url)
		defer res.Body.Close()
		fmt.Println(res.StatusCode)
		time.Sleep(10 * time.Second)
	}
}
