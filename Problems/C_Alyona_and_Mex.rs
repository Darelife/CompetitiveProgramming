/*
  Darelife's Solution
  -------------------
  We need to find the max mex after performing the ops on the arr

  We first sort the array to make it easier to find the mex

  We are gonna use a greedy approach to find the mex, so start with ans = 1 (min possible)
  If we find any a[i] >= ans, then we increment ans by 1, because there exists an element in the array, which is
  equal to or, can be reduced to ans, so we can't have ans as the mex.
*/

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut a: Vec<i32> = (0..n)
        .map(|_| iter.next().unwrap().parse().unwrap())
        .collect();
    a.sort();
    // println!("{:?}", a);
    let mut ans = 1;
    for i in 0..n {
        if a[i] >= ans {
            ans += 1;
        }
    }
    println!("{}", ans);
}
