#include <stdio.h>

void genKey(int);
int gcd(int, int);
int euclidian(int, int);
int encrypt(char, int);
int decrypt(int, int);
int power(int, int, int); // Modular exponentiation

int Pkey, Prikey;

int main() {
    int p, q;
    int n, piN;

    // Step 1: Input two prime numbers
    scanf("%d %d", &p, &q);

    n = p * q;                    // Modulus
    piN = (p - 1) * (q - 1);      // Euler's totient function

    genKey(piN);                 // Generate public/private keys

    char ch;
    scanf(" %c", &ch);           // Input character to encrypt (note space before %c to skip newline)

    int encrypted = encrypt(ch, n);
    int decrypted = decrypt(encrypted, n);

    printf("Encrypted: %d\n", encrypted);
    printf("Decrypted: %c\n", decrypted);

    // Correct comparison: check if decrypted matches original character
    if (decrypted == (int)ch) 
	{
        printf("Successful\n");
    } 
	else 
	{
        printf("Failed\n");
    }

    return 0;
}

void genKey(int n) {
    int i;
    for (i = 2; i < n; i++) 
	{
        if (gcd(n, i) == 1) 
		{
            Pkey = i;       // Public key e
            break;
        }
    }
    Prikey = euclidian(n, Pkey);  // Private key d
}

int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int euclidian(int a, int b)
{
    int t1 = 0, t2 = 1, t, q, r, A = a;
    while (b != 0) 
	{
        q = a / b;
        r = a % b;
        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
        a = b;
        b = r;
    }
    return (t1 < 0) ? (t1 + A) : t1;  // Ensure d is positive
}

// Modular exponentiation
int power(int base, int exp, int mod) 
{
    int result = 1;
    base = base % mod;
    while (exp > 0) 
	{
        if (exp % 2 == 1)
        {
        	result = (result * base) % mod;
		}
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

// Encrypt character using public key
int encrypt(char ch, int n)
{
    return power((int)ch, Pkey, n);
}

// Decrypt integer using private key
int decrypt(int encrypted, int n) 
{
    return power(encrypted, Prikey, n);
}