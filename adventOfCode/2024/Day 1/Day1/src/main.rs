use std::fs::File;
use std::io::{self, BufRead, BufReader, Write};
use std::path::Path;

fn solve(input: &mut dyn BufRead, output: &mut dyn Write) -> io::Result<()> {
    let mut a = vec![0; 1000];
    let mut b = vec![0; 1000];

    for i in 0..1000 {
        let mut line = String::new();
        input.read_line(&mut line)?;
        let nums: Vec<i32> = line
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        a[i] = nums[0];
        b[i] = nums[1];
    }

    a.sort();
    b.sort();

    let mut ans = 0;
    for i in 0..1000 {
        ans += (a[i] - b[i]).abs();
    }

    writeln!(output, "{}", ans)?;
    Ok(())
}

fn main() -> io::Result<()> {
    let input_path = Path::new("1a.txt");
    let output_path = Path::new("output.txt");

    let input_file = File::open(&input_path)?;
    let mut input = BufReader::new(input_file);

    let output_file = File::create(&output_path)?;
    let mut output = io::BufWriter::new(output_file);

    solve(&mut input, &mut output)
}
