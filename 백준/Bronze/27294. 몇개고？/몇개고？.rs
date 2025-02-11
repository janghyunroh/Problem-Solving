use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    
    let numbers: Vec<i32> = input
        .split_whitespace()
        .map(|s| s.parse().expect("Invalid number"))
        .collect();
    
    let (a, b) = (numbers[0], numbers[1]);
    
    if a >= 12 && a <= 16 && b == 0 {
        println!("{}", 320);  
    } else {
        println!("{}", 280);
    }
}
