#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

class genome
{
private:
    string RNA;
    string DNA;
    string reshte1;
    string reshte2;
public:
    //start constructor (and maybe distructor)
    //genome();
    //end constructor
    // start cin
    void DNAcin()
    {
        string x, y;
        cout << "reshte ye avvale DNA : ";
        cin >> x;
        cout << "reshte ye dovvome DNA : ";
        cin >> y;
        reshte1 = x;
        reshte2 = y;
        DNA = x + y;
    }
    //start DNA & RNA getter and setters
    string getDNA()
    {
        return DNA;
    }
    string getRNA()
    {
        return RNA;
    }
    string getreshte1()
    {
        return reshte1;
    }
    string getreshte2()
    {
        return reshte2;
    }
    void setDNA(string x)
    {
        DNA = x;
    }
    void setRNA(string x)
    {
        RNA = x;
    }
    void setr1(string x)
    {
        reshte1 = x;
    }
    void setr2(string x)
    {
        reshte2 = x;
    }
    //end DNA & RNA getter and setters
    // start DNA build from RNA
    string DNAbuild()
    {
        string answer = "";
        int n = size(RNA);
        for (int i = 0; i < n; i++)
        {
            if (RNA[i] == 65)
            {
                answer = answer + "T";
            }
            if (RNA[i] == 84)
            {
                answer = answer + "A";
            }
            if (RNA[i] == 67)
            {
                answer = answer + "G";
            }
            if (RNA[i] == 71)
            {
                answer = answer + "C";
            }
        }
        return answer;
    }
    // end DNA build from RNA
    // start RNAminijump
    void RNAminijump(char x, char y, int n)
    {
        int m = 0;
        for (int i = 0; i < size(RNA); i++)
        {
            if (m < n && RNA[i] == x)
            {
                RNA[i] = y;
                m++;
            }
        }
    }
    // end RNAminijump 
    // start DNAminijump
    void DNAminijump(char x, char y, int n)
    {
        string k = reshte1;
        string f = reshte2;
        int j = size(k);
        int total = 0;
        for (int i = 0; i < j; i++)
        {
            if (k[i] == x)
            {
                k[i] = y;
                if (k[i] == 65)
                {
                    f[i] = 84;
                }
                if (k[i] == 84)
                {
                    f[i] = 65;
                }
                if (k[i] == 67)
                {
                    f[i] = 71;
                }
                if (k[i] == 71)
                {
                    f[i] = 67;
                }
                i = i + 1;
                total++;
            }
            if (total == n)
            {
                break;
            }
            if (f[i] == x)
            {
                f[i] = y;
                if (f[i] == 65)
                {
                    k[i] = 84;
                }
                if (f[i] == 84)
                {
                    k[i] = 65;
                }
                if (f[i] == 67)
                {
                    k[i] = 71;
                }
                if (f[i] == 71)
                {
                    k[i] = 67;
                }
                total++;

            }
            if (total == n)
            {
                break;
            }
        }
        reshte1 = k;
        reshte2 = f;
        DNA = k + f;
    }
    // end DNAminijump
    // start RNAgreatjump
    string RNAgreatjump(string x, string y)
    {
        string answer = "";
        int j = size(x);
        int total = 0;
        int i = 0;
        while (i < size(RNA) - j)
        {
            for (int m = 0; m < j; m++)
            {
                int n = i + m;
                if (RNA[n] == x[m])
                {
                    total++;
                }

            }
            if (total == j)
            {
                answer = answer + y;
                i = i + j;
                break;
            }
            else
            {
                answer = answer + RNA[i];
                i++;
            }
            total = 0;
        }
        for (i; i < size(RNA); i++)
        {
            answer = answer + RNA[i];
        }
        RNA = answer;
        return answer;
    }
    //end RNA great jump
    //start DNA great jump
    void DNAgreatjump(string x, string y)
    {
        string r1 = "";
        string r2 = "";
        int j = size(x);
        int u = size(DNA) / 2;
        int number = 0;
        int total = 0;
        int i = 0;
        while (i < u - j + 1)
        {
            //reshte1
            for (int m = 0; m < j; m++)
            {
                int n = i + m;
                if (reshte1[n] == x[m])
                {
                    total++;
                }

            }

            if (total == j)
            {
                r1 = r1 + y;
                i = i + j;
                number = 1;
                break;
            }
            else
            {
                r1 = r1 + reshte1[i];
            }
            total = 0;
            //reshte2
            for (int m = 0; m < j; m++)
            {
                int n = i + m;
                if (reshte2[n] == x[m])
                {
                    total++;
                }

            }
            if (total == j)
            {
                r2 = r2 + y;
                i = i + j;
                number = 2;
                break;
            }
            else
            {
                r2 = r2 + reshte2[i];
            }
            i++;
            total = 0;
        }
        if (number == 1)
        {
            for (i; i < size(reshte1); i++)
            {
                r1 = r1 + reshte1[i];
            }
            reshte1 = r1;
            string resh2 = "";
            int n = size(reshte1);
            for (int i = 0; i < n; i++)
            {
                if (reshte1[i] == 65)
                {
                    resh2 = resh2 + "T";
                }
                if (reshte1[i] == 84)
                {
                    resh2 = resh2 + "A";
                }
                if (reshte1[i] == 67)
                {
                    resh2 = resh2 + "G";
                }
                if (reshte1[i] == 71)
                {
                    resh2 = resh2 + "C";
                }
            }
            reshte2 = resh2;
            DNA = reshte1 + reshte2;
        }
        if (number == 2)
        {
            for (i; i < size(reshte2); i++)
            {
                r2 = r2 + reshte2[i];
            }
            reshte2 = r2;
            string resh1 = "";
            int n = size(reshte2);
            for (int i = 0; i < n; i++)
            {
                if (reshte2[i] == 65)
                {
                    resh1 = resh1 + "T";
                }
                if (reshte2[i] == 84)
                {
                    resh1 = resh1 + "A";
                }
                if (reshte2[i] == 67)
                {
                    resh1 = resh1 + "G";
                }
                if (reshte2[i] == 71)
                {
                    resh1 = resh1 + "C";
                }
            }
            reshte1 = resh1;
            DNA = reshte1 + reshte2;
        }
    }
    //end DNA great jump
    //start RNA reverse jump
    void RNAreversejump(string x)
    {
        string answer = "";
        int j = size(x);
        string xreverse = "";
        for (int u = j - 1; u >= 0; u--)
        {
            xreverse = xreverse + x[u];
        }

        int total = 0;
        int i = 0;
        while (i < size(RNA) - j)
        {
            for (int m = 0; m < j; m++)
            {
                int n = i + m;
                if (RNA[n] == x[m])
                {
                    total++;
                }

            }
            if (total == j)
            {
                answer = answer + xreverse;
                i = i + j;
                break;
            }
            else
            {
                answer = answer + RNA[i];
                i++;
            }
            total = 0;
        }
        for (i; i < size(RNA); i++)
        {
            answer = answer + RNA[i];
        }
        RNA = answer;

    }
    //end RNA reverse jump
    // start DNA reverse jump
    void DNAreversejump(string x)
    {
        string r1 = "";
        string r2 = "";
        string y = "";
        for (int h = size(x) - 1; h >= 0; h--)
        {
            y = y + x[h];
        }

        int j = size(x);
        int u = size(DNA) / 2;
        int number = 0;
        int total = 0;
        int i = 0;
        while (i < u - j + 1)
        {
            //reshte1
            for (int m = 0; m < j; m++)
            {
                int n = i + m;
                if (reshte1[n] == x[m])
                {
                    total++;
                }

            }

            if (total == j)
            {
                r1 = r1 + y;
                i = i + j;
                number = 1;
                break;
            }
            else
            {
                r1 = r1 + reshte1[i];
            }
            total = 0;
            //reshte2
            for (int m = 0; m < j; m++)
            {
                int n = i + m;
                if (reshte2[n] == x[m])
                {
                    total++;
                }

            }
            if (total == j)
            {
                r2 = r2 + y;
                i = i + j;
                number = 2;
                break;
            }
            else
            {
                r2 = r2 + reshte2[i];
            }
            i++;
            total = 0;
        }
        if (number == 1)
        {
            for (i; i < size(reshte1); i++)
            {
                r1 = r1 + reshte1[i];
            }
            reshte1 = r1;
            string resh2 = "";
            int n = size(reshte1);
            for (int i = 0; i < n; i++)
            {
                if (reshte1[i] == 65)
                {
                    resh2 = resh2 + "T";
                }
                if (reshte1[i] == 84)
                {
                    resh2 = resh2 + "A";
                }
                if (reshte1[i] == 67)
                {
                    resh2 = resh2 + "G";
                }
                if (reshte1[i] == 71)
                {
                    resh2 = resh2 + "C";
                }
            }
            reshte2 = resh2;
            DNA = reshte1 + reshte2;
        }
        if (number == 2)
        {
            for (i; i < size(reshte2); i++)
            {
                r2 = r2 + reshte2[i];
            }
            reshte2 = r2;
            string resh1 = "";
            int n = size(reshte2);
            for (int i = 0; i < n; i++)
            {
                if (reshte2[i] == 65)
                {
                    resh1 = resh1 + "T";
                }
                if (reshte2[i] == 84)
                {
                    resh1 = resh1 + "A";
                }
                if (reshte2[i] == 67)
                {
                    resh1 = resh1 + "G";
                }
                if (reshte2[i] == 71)
                {
                    resh1 = resh1 + "C";
                }
            }
            reshte1 = resh1;
            DNA = reshte1 + reshte2;
        }
    }
    //end DNA reverse jump
};


class cell : public genome
{
private:
    vector <genome> cellgen;
    int chromosomenumber;
public:
    void chromosomecin()
    {
        int x;
        cout << "Chromosome number : ";
        cin >> x;
        chromosomenumber = x;
        int i = 0;
        while (i < x)
        {
            genome m;
            cout << "Chromosome " << i + 1 << " : " << endl;
            string x, y;
            cout << "reshte ye avvale DNA : ";
            cin >> x;
            cout << "reshte ye dovvome DNA : ";
            cin >> y;
            m.setr1(x);
            m.setr2(y);
            m.setDNA(x + y);
            cellgen.push_back(m);
            i++;
        }
    }
    // celldeath moshkel dare
    // getter an setters
    int getchromosomenumber()
    {
        return chromosomenumber;
    }
    void setchromosomenumber(int y)
    {
        chromosomenumber = y;
    }
    vector <genome> getcellgen()
    {
        return cellgen;
    }
    void setcellgen(vector <genome> x)
    {
        cellgen = x;
    }
    //
    void celldeath()
    {
        int i = 0;
        while (i < chromosomenumber)
        {
            string r1 = cellgen[i].getreshte1();
            string r2 = cellgen[i].getreshte2();
            int t1 = 0;
            int joftAT = 0;
            int joftCG = 0;
            for (int m = 0; m < size(r1); m++)
            {

                if (r1[m] == 65 && r2[m] == 84)
                {
                    joftAT++;
                }
                if (r2[m] == 65 && r1[m] == 84)
                {
                    joftAT++;
                }

                if (r1[m] == 67 && r2[m] == 71)
                {
                    joftCG++;
                }
                if (r2[m] == 67 && r1[m] == 71)
                {
                    joftCG++;
                }

                if (r1[m] == 65 && r2[m] != 84)
                {
                    t1++;
                }
                if (r1[m] != 65 && r2[m] == 84)
                {
                    t1++;
                }
                if (r2[m] == 65 && r1[m] != 84)
                {
                    t1++;
                }
                if (r2[m] != 65 && r1[m] == 84)
                {
                    t1++;
                }
                //
                if (r1[m] == 67 && r2[m] != 71)
                {
                    t1++;
                }
                if (r1[m] != 67 && r2[m] == 71)
                {
                    t1++;
                }
                if (r2[m] == 67 && r1[m] != 71)
                {
                    t1++;
                }
                if (r2[m] != 67 && r1[m] == 71)
                {
                    t1++;
                }
            }
            if ((t1 / 2) > 5 || joftAT > (3 * joftCG))
            {
                vector <genome> cellg2;
                for (int j = 0; j < i; j++)
                {
                    cellg2.push_back(cellgen[j]);
                }
                for (int h = i + 1; h < size(cellgen); h++)
                {
                    cellg2.push_back(cellgen[h]);
                }
                cellgen = cellg2;
                chromosomenumber = chromosomenumber - 1;
                i = i - 1;
            }
            i++;
        }
    }
    void chromminijump(char x, char y, int n, int m)
    {
        string k = cellgen[m - 1].getreshte1();
        string f = cellgen[m - 1].getreshte2();
        int j = size(k);
        int total = 0;
        for (int i = 0; i < j; i++)
        {
            if (k[i] == x)
            {
                k[i] = y;
                if (k[i] == 65)
                {
                    f[i] = 84;
                }
                if (k[i] == 84)
                {
                    f[i] = 65;
                }
                if (k[i] == 67)
                {
                    f[i] = 71;
                }
                if (k[i] == 71)
                {
                    f[i] = 67;
                }
                total++;
            }
            if (f[i] == x)
            {
                f[i] = y;
                if (f[i] == 65)
                {
                    k[i] = 84;
                }
                if (f[i] == 84)
                {
                    k[i] = 65;
                }
                if (f[i] == 67)
                {
                    k[i] = 71;
                }
                if (f[i] == 71)
                {
                    k[i] = 67;
                }
                total++;

            }
            if (total == n)
            {
                break;
            }
        }
        cellgen[m - 1].setr1(k);
        cellgen[m - 1].setr2(f);
        cellgen[m - 1].setDNA(k + f);
        cout << endl << "Chromosome M after mini jump : " << endl;
        cout << k << endl << f;
    }
    void chromgreatjump(string s1, string s2, int n, int m)
    {
        genome rna11, rna12, rna21, rna22;
        string r1n = cellgen[n - 1].getreshte1();
        string r2n = cellgen[n - 1].getreshte2();
        string r1m = cellgen[m - 1].getreshte1();
        string r2m = cellgen[m - 1].getreshte2();
        rna11.setRNA(r1n);
        rna12.setRNA(r2n);
        rna21.setRNA(r1m);
        rna22.setRNA(r2m);

        string s11 = "";
        for (int i = 0; i < size(s1) / 2; i++)
        {
            s11 = s11 + s1[i];
        }
        string s12 = "";
        for (int i = size(s1) / 2; i < size(s1); i++)
        {
            s12 = s12 + s1[i];
        }
        string s21 = "";
        for (int i = 0; i < size(s2) / 2; i++)
        {
            s21 = s21 + s2[i];
        }
        string s22 = "";
        for (int i = size(s2) / 2; i < size(s2); i++)
        {
            s22 = s22 + s2[i];
        }
        string ns1 = rna11.RNAgreatjump(s11, s21);
        string ns2 = rna12.RNAgreatjump(s12, s22);
        string ms1 = rna21.RNAgreatjump(s21, s11);
        string ms2 = rna22.RNAgreatjump(s22, s12);

        cellgen[n - 1].setr1(ns1);
        cellgen[n - 1].setr2(ns2);
        cellgen[m - 1].setr1(ms1);
        cellgen[m - 1].setr2(ms2);
        cellgen[n - 1].setDNA(ns1 + ns2);
        cellgen[m - 1].setDNA(ms1 + ms2);
        cout << "Chromosome N after great jump : " << endl << ns1 << endl << ns2 << endl;
        cout << "Chromosome N after great jump : " << endl << ms1 << endl << ms2 << endl;

    }
    void chromreversejump(string s1, int n)
    {
        genome k, p;
        string r1 = cellgen[n - 1].getreshte1();
        string r2 = cellgen[n - 1].getreshte2();
        k.setRNA(r1);
        p.setRNA(r2);
        int m = size(s1);
        string s11 = "";
        for (int i = 0; i < size(s1) / 2; i++)
        {
            s11 = s11 + s1[i];
        }
        string s12 = "";
        for (int i = size(s1) / 2; i < size(s1); i++)
        {
            s12 = s12 + s1[i];
        }
        string revs11 = "";
        for (int i = size(s11) - 1; i >= 0; i--)
        {
            revs11 = revs11 + s11[i];
        }
        string revs12 = "";
        for (int i = size(s12) - 1; i >= 0; i--)
        {
            revs12 = revs12 + s12[i];
        }

        string ns1 = k.RNAgreatjump(s11, revs11);
        string ns2 = p.RNAgreatjump(s12, revs12);

        cellgen[n - 1].setr1(ns1);
        cellgen[n - 1].setr2(ns2);
        cellgen[n - 1].setDNA(ns1 + ns2);
        cout << "Chromosome N after reverse jump : " << endl << ns1 << endl << ns2 << endl;


    }
    void palindrom(int n)
    {
        cout << "palindroms in line 1 : " << endl;
        string r1 = cellgen[n - 1].getreshte1();
        for (int i = 0; i < size(r1) - 2; i++)
        {
            for (int m = i + 2; m < size(r1); m++)
            {
                string k = "";
                for (int d = i; d <= m; d++)
                {
                    k = k + r1[d];
                }
                genome x;
                x.setRNA(k);
                string s = x.DNAbuild();
                string reversek = "";
                for (int u = size(s) - 1; u >= 0; u--)
                {
                    reversek = reversek + s[u];
                }
                if (reversek == k)
                {
                    cout << k << endl;
                }

            }
        }
        cout << "palindroms in line 2 : " << endl;
        string r2 = cellgen[n - 1].getreshte2();
        for (int i = 0; i < size(r2) - 2; i++)
        {
            for (int m = i + 2; m < size(r2); m++)
            {
                string k = "";
                for (int d = i; d <= m; d++)
                {
                    k = k + r2[d];
                }
                genome x;
                x.setRNA(k);
                string s = x.DNAbuild();
                string reversek = "";
                for (int u = size(s) - 1; u >= 0; u--)
                {
                    reversek = reversek + s[u];
                }
                if (reversek == k)
                {
                    cout << k << endl;
                }

            }
        }
    }
};
