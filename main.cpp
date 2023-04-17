#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Cell.h>
#include <Animal.h>
#include <vector>

using namespace std;

// start main
int main()
{
    //menu
    cout << "                    Welcome!" << endl;
    while (1 == 1)
    {
        char a = 201;
        char c = 205;
        char b = 186;
        char d = 204;
        char k = 187;
        char l = 185;
        char f = 176;
        char m = 200;
        char n = 188;

        cout << a << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << k << endl << b << "  " << "Choose number of function from follow list" << "  " << b << endl;
        cout << d << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << l;
        int x;
        cout << endl << b << "           " << f << " Genome functions list " << f << "          " << b << endl << d << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << l;
        cout << endl << b << "              " << "(1) RNA mini jump" << "               " << b;
        cout << endl << b << "              " << "(2) RNA great jump" << "              " << b;
        cout << endl << b << "              " << "(3) RNA reverse jump" << "            " << b;
        cout << endl << b << "              " << "(4) DNA mini jump" << "               " << b;
        cout << endl << b << "              " << "(5) DNA great jump" << "              " << b;
        cout << endl << b << "              " << "(6) DNA reverse jump" << "            " << b;
        cout << endl << d << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << l;
        cout << endl << b << "            " << f << " Cell functions list " << f << "           " << b << endl << d << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << l;
        cout << endl << b << "              " << "(8) Cell death" << "                  " << b;
        cout << endl << b << "              " << "(9) Chromosome mini jump" << "        " << b;
        cout << endl << b << "              " << "(10) Chromosome great jum" << "       " << b;
        cout << endl << b << "              " << "(11) Chromosome reverse jump" << "    " << b;
        cout << endl << b << "              " << "(12) Palindrom" << "                  " << b;
        cout << endl << d << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << l;
        cout << endl << b << "           " << f << " Animal functions list " << f << "          " << b << endl << d << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << l;
        cout << endl << b << "             " << "(13) Similarity percentage" << "       " << b;
        cout << endl << b << "             " << "(14) Same Species" << "                " << b;
        cout << endl << b << "             " << "(15) Asexual reproduction" << "        " << b;
        cout << endl << b << "             " << "(16) Sexual reproduction" << "         " << b;
        cout << endl << b << "             " << "(17) Cell death" << "                  " << b;
        cout << endl << m << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << n << endl;
        cin >> x;
        system("CLS");

        if (x == 1)
        {
            genome k;
            cout << "This function replace N Nucleotide X with Nucleotide Y in RNA " << endl;
            string y;
            cout << endl << "Please enter the RNA : ";
            cin >> y;
            k.setRNA(y);
            cout << endl << "Please enter the X , Y and N respectively : ";
            char u, s;
            int n;
            cin >> u >> s;
            cin >> n;
            k.RNAminijump(u, s, n);
            string h = k.getRNA();
            cout << endl << "RNA after mini jump : " << h << endl;
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 2)
        {
            genome k;
            cout << "This function replace S1 with S2 in RNA " << endl;
            string y;
            cout << endl << "Please enter the RNA : ";
            cin >> y;
            k.setRNA(y);
            cout << endl << "Please enter the S1 and S2 respectively : ";
            string u, s;
            cin >> u >> s;
            string h = k.RNAgreatjump(u, s);
            cout << endl << "RNA after great jump : " << h << endl;
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 3)
        {
            genome k;
            cout << "This function reverse S1 in RNA " << endl;
            string y;
            cout << endl << "Please enter the RNA : ";
            cin >> y;
            k.setRNA(y);
            cout << endl << "Please enter the S1 : ";
            string s1;
            cin >> s1;
            k.RNAreversejump(s1);
            string h = k.getRNA();
            cout << endl << "reversed jump RNA: " << h << endl;
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 4)
        {
            genome k;
            cout << "This function replace N Nucleotide X with Nucleotide Y in DNA " << endl;
            cout << endl << "Please enter the DNA" << endl;
            k.DNAcin();
            cout << endl << "Please enter the X , Y and N respectively : ";
            char u, s;
            int n;
            cin >> u >> s;
            cin >> n;
            k.DNAminijump(u, s, n);
            string h = k.getreshte1();
            string l = k.getreshte2();
            cout << endl << "DNA after mini jump : " << endl << h << endl << l << endl;
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 5)
        {
            genome k;
            cout << "This function replace S1 with S2 in DNA " << endl;
            cout << endl << "Please enter the DNA " << endl;
            k.DNAcin();
            cout << endl << "Please enter the S1 and S2 respectively : ";
            string u, s;
            cin >> u >> s;
            k.DNAgreatjump(u, s);
            string h = k.getreshte1();
            string l = k.getreshte2();
            cout << endl << "DNA after great jump : " << endl << h << endl << l << endl;
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 6)
        {
            genome k;
            cout << "This function reverse one part of DNA (S1)" << endl;
            cout << endl << "Please enter the DNA " << endl;
            k.DNAcin();
            cout << "Please enter S1 : ";
            string s1;
            cin >> s1;
            k.DNAreversejump(s1);
            string a = k.getreshte1();
            string b = k.getreshte2();
            cout << endl << "DNA after reverse DNA : " << endl << a << endl << b << endl;
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 7)
        {
            genome k;
            cout << "This function build DNA with your RNA" << endl;
            cout << endl << "Please enter the RNA : ";
            string r;
            cin >> r;
            k.setRNA(r);
            string n = k.DNAbuild();
            cout << endl << "DNA after build DNA : " << endl << r << endl << n << endl;
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 8)
        {
            cell k;
            cout << "This function remove bad chromosomes" << endl;
            k.chromosomecin();
            int x = k.getchromosomenumber();
            k.celldeath();
            int m = k.getchromosomenumber();
            cout << endl << "Removed chromosomes number : " << x - m << endl;
            cout << "Remaining chromosomes number : " << m << endl;
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 9)
        {
            cell k;
            cout << "This function replace N Nucleotide X with Nucleotide Y in chromosome M " << endl;
            k.chromosomecin();

            cout << endl << "Please enter the X , Y , N and M respectively : ";
            char u, s;
            int n, m;
            cin >> u >> s;
            cin >> n >> m;
            k.chromminijump(u, s, n, m);
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 10)
        {
            cell k;
            cout << "This function replace S2(from chromosome N) with S2(from chromosome M) and inverse " << endl;
            k.chromosomecin();
            cout << endl << "Please enter the S1 , S2 , N and M respectively : ";
            string u, s;
            int n, m;
            cin >> u >> s;
            cin >> n >> m;
            k.chromgreatjump(u, s, n, m);
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 11)
        {
            cell k;
            cout << "This function reverse S1 in chromosome N " << endl;
            k.chromosomecin();
            cout << endl << "Please enter the S1 and N : ";
            string u;
            int n;
            cin >> u;
            cin >> n;
            k.chromreversejump(u, n);
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 12)
        {
            cell k;
            cout << "This function find palindroms in chromosome N " << endl;
            k.chromosomecin();
            cout << endl << "Please enter the N : ";
            int n;
            cin >> n;
            k.palindrom(n);
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 13)
        {
            Animal k;
            Animal t;

            cout << "This function find similarity percentage of two cells " << endl;
            k.getanimal();
            t.getanimal();
            int l = k.Animalps(k, t);
            if (l == -1)
            {
                cout << "chromosome number of clee are not equal!";
            }
            else
            {
                cout << "percentage two cells " << l << "%";
            }
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 14)
        {
            Animal k;
            Animal t;

            cout << "This function check the equality of two animals " << endl;
            k.getanimal();
            t.getanimal();
            bool h = k == t;
            if (!h)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 15)
        {
            Animal k;
            Animal t;

            cout << "This function Animal child after Asexual reproduction " << endl;
            k.getanimal();
            cell d = k.Animalar(k);
            int tt = d.getchromosomenumber();
            vector <genome> dd;
            dd = d.getcellgen();
            cout << "Chromosomes of child : " << endl;
            for (int i = 0; i < tt; i++)
            {
                string a1 = dd[i].getreshte1();
                string a2 = dd[i].getreshte2();
                cout << "Chromosome " << i + 1 << " :" << endl;
                cout << a1 << endl << a2 << endl;
            }
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 16)
        {
            Animal k;
            Animal t;

            cout << "This function Animal child after sexual reproduction " << endl;
            k.getanimal();
            t.getanimal();
            cell d = k + t;
            int tt = d.getchromosomenumber();
            vector <genome> dd;
            dd = d.getcellgen();
            cout << "Chromosomes of child : " << endl;
            for (int i = 0; i < tt; i++)
            {
                string a1 = dd[i].getreshte1();
                string a2 = dd[i].getreshte2();
                cout << "Chromosome " << i + 1 << " :" << endl;
                cout << a1 << endl << a2 << endl;
            }

            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }
        if (x == 17)
        {
            Animal k;
            cout << "This function remove bad chromosomes from animal cells " << endl;
            k.getanimal();
            cell u = k.getanimalcell();
            int x = u.getchromosomenumber();
            k.Animalcellsdeath();
            cell f = k.getanimalcell();
            int m = f.getchromosomenumber();
            cout << endl << "Removed chromosomes number : " << x - m << endl;
            cout << "Remaining chromosomes number : " << m << endl;
            cout << endl << "exit or continue (e/c) ? ";
            char j;
            cin >> j;
            if (j == 101)
            {
                break;
            }
            system("CLS");
        }

    }
    return 0;
}
// end main
