Just the basics. So, we'll start with what all the regular bit masking ops do.
- Or
- and
- xor
- xnor

### LSB trick
LSB = x&1

### Check if it's a power of 2
x  = 010000000
x-1 = 001111111
x&(x-1) = 0

but this doesn't work if x = 0

so, it's a power of 2 if, `x && !(x&(x-1))`

### Kth bit
So, if x = 100100111000
kth bit from the right

to check if the kth bit is set, x&(1<<k)
to toggle the kth bit, x^(1<<k)
to set the kth bit, x|(1<<k)
to unset the kth bit, x&(~(1<<k))

### Multiply / Divide by 2^k
to multiply, left shift, and to divide, right shift by k

### Find x%2^k
x&((1<<k)-1)
it's faster than x%(1<<k), as bitwise ops are single instructions, while modulo involves division, which is a relatively expensive operation. Also, actually, addition and subtraction is an O(N) operation. Where N is the number of bits (in the case of large numbers). For our regular 32 bit/64 bit numbers, (based on the cpu), they can be O(1). But for larger numbers, like, in python when u reach a size larger than the limit of the register size of the cpu, addition/subtraction becomes O(N), and multiplication/division becomes O(N^2). And for this, we have some crazy algorithms like, karatsuba and toom-cook, or FFT that can do it better than O(N^2).

### Swapping 2 numbers without a temp variable
x = 2, y = 5
(xor swap)
x=x ^ y                (x = x ^ y, y = y)
y = x ^ y              (x = x^y, y = x^y^y=x)
x = x ^ y              (x = x^y^x = y, y = x)

there's also an arithmetic swap
x = x + y
y = x - y
x = x - y

XOR SWAP
xor eax, ebx
xor ebx, eax
xor eax, ebx


TEMP SWAP
mov ecx, eax
mov eax, ebx
mov ebx, ecx


however, mov operation is extremely fast
while the xor ops have data dependencies as each line depends on the result of the previous ones. There's a thing called pipelining, and becuz of that, TEMP is extremely fast, while in XOR, we'll have to have a few empty cycles and all.


### Property
Number of set bits in A = x,
number of set bits in B = y
Number of set bits in A^B = z

z&1 = (x+y)&1

this is cuz, if we have 0 ^ 1 or 1 ^ 0....we get 1. So, we can see that the parity makes sense, as (1+0)%2 == 1%2

and if we get 0 ^ 0 or 1 ^ 1, we get 0....so, again, (1+1)%2 == (0+0)%2 == 0%2

### Some other identities
A+B  = (A^B) (All the bits that aren't same in A and B)+ 2 (A&B) (All the bits that are same in A and B)
A+B = (A|B) + (A&B)

### popcount
__builtin_popcount(x) and __builtin_popcountll(x)



## A random q
given a set of numbers, we want to find the sum of all subsets.

```cpp
int sum_of_all_subset ( vector< int > s ){
    int n = s.size() ;
    vector<int> results(1<<n, 0);
    for( int i = 0 ; i < ( 1 << n ) ; ++ i ) {
        for ( int j = 0; j < n ; ++ j ) {
            if ( ( i & ( 1 << j ) ) ) 
                results[i] += s [j] ;
        }
    }
}
```
