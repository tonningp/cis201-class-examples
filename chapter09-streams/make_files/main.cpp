#include<iostream>
#include<string>
#include<fstream>

/* atoi: convert s to integer */
int atoi(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

/* strlen: return length of s */
int strlen(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    std::ifstream input;
    //for(int count=1; count < 101;count++)
    int count = 1;
    for(;;)
    {
        char buffer[10];
	    itoa(count,buffer);
        std::string filename = "data" + std::string(buffer) + ".txt";
        std::cout << "writing to: " << filename << std::endl;
        input.open("data.txt");
        std::ofstream output;
        output.open(filename.c_str());
        if( !input.fail())
        {
            for(;;)
            {
                char c;
                input.get(c);
                if(input.eof())
                    break;
                output.put(c);
            }
        }
        output.close();
        input.close();
        count++;
    }

    return 0;
}
