n = int(input())

def nChoosek(n, k ):
    if (k > n):
        return 0;
    if (k * 2 > n):
        k = n-k;
    if (k == 0):
        return 1;

    result = n;

    for i in range(2,k+1):
        result *= (n-i+1);
        result //= i;

    return result;

print(nChoosek(2 * (n+1), n+1) // (n+2))