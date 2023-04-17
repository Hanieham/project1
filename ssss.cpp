#include <iostream>
#include <string>
#include <vector>
using namespace std;

//start genome class
class genome
{
private:
    friend class cell;
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
            if (m < n && RNA[i] == x )
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
        cout << reshte1 << endl << reshte2;


    }
    //end DNA reverse jump
};
// end genome class

//start cell class
class cell
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
        int getcellgen()
        {
            //return cellgen;
        }
        //
        void celldeath()
        {
            for (int i = 0; i < chromosomenumber; i++)
            {
                string r1 = cellgen[i].getreshte1();
                string r2 = cellgen[i].getreshte2();
                int t1 = 0;
                int t2 = 0;
                for (int m = 0; m < size(r1); m++)
                {

                    if (r1[m] == 65 && r2[m] == 84)
                    {
                        t2++;
                    }
                    if (r2[m] == 65 && r1[m] == 84)
                    {
                        t2++;
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
                if (t1 > 5)
                {
                    if (i == 0)
                    {
                        cellgen.erase(cellgen.begin());
                    }
                    if (i != 0)
                    {
                        cellgen.erase(cellgen.begin() + i);
                    }
                }
                if (t2 > ((size(r1) - t1) / 3))
                {
                    if (i == 0)
                    {
                        cellgen.erase(cellgen.begin());
                    }
                    if (i != 0)
                    {
                        cellgen.erase(cellgen.begin() + i);
                    }
                }
            }
            cout << size(cellgen);
        }
        void DNAminijump(char x, char y, int n, int m)
        {
            string k = cellgen[m-1].reshte1;
            string f = cellgen[m-1].reshte2;
            int j = size(k);
            int total = 0;
            for (int i = 0; i < j ; i++)
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
            cellgen[m-1].setr1(k);
            cellgen[m-1].setr2(f);
            cellgen[m-1].setDNA(k + f);
            cout << k << endl << f;
        }
        void DNAgreatjump(string s1, string s2, int n, int m)
        {
            genome rna11, rna12, rna21, rna22;
            string r1n = cellgen[n-1].reshte1;
            string r2n = cellgen[n-1].reshte2;
            string r1m = cellgen[m-1].reshte1;
            string r2m = cellgen[m-1].reshte2;
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
            string ns11 = rna11.RNAgreatjump(s11, s21);
            string ns12 = rna12.RNAgreatjump(s12, s22);
            string ns21 = rna21.RNAgreatjump(s21, s11);
            string ns22 = rna22.RNAgreatjump(s22, s12);

            cellgen[n - 1].setr1(ns11);
            cellgen[n - 1].setr2(ns12);
            cellgen[m - 1].setr1(ns21);
            cellgen[m - 1].setr2(ns22);
            cellgen[n - 1].setDNA(ns11 + ns12);
            cellgen[n - 1].setDNA(ns21 + ns22);

            cout << ns11 << endl << ns12 << endl << ns21 << endl << ns22;

        }
        void DNAreversejump(string s1, int n) // **
        {
            genome k, p;
            string r1 = cellgen[n].getreshte1();
            string r2 = cellgen[n].getreshte2();
            k.setRNA(r1);
            p.setRNA(r2);
            string r11 = "";
            string r22 = "";
            int m = size(s1);
            
        }
        void palindrom(int n)
        {
            cout << "palindroms in line 1 : " << endl;
            string r1 = cellgen[n-1].getreshte1();
            for (int i = 0; i < size(r1)-2; i++)
            {
                for (int m = i+2; m < size(r1) ; m++)
                {
                    string k = "";
                    for (int d = i; d <= m ; d++)
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
// end cell class
// start class Animal
/*
class Animal
{
    private :
        vector <cell> animalcell;
        int animalnumber = 0;
    public :
        Animalcellcin()
        {
            cout << "Tedade heyvanate morede nazar ra vared konid : ";
            int m;
            cin >> m;
            animalnumber = m;
            for (int i = 0; i < m; i++)
            {
                cell t;
                t.chromosomecin();
                animalcell.push_back(t);
            }
        }
        bool Animalps(int n, int m)
        {
            int ncromnum, mcromnum;
            vector <genome> ncromlist;
            vector <genome> mcromlist;
            ncromnum = animalcell[n - 1].getchromosomenumber();
            mcromnum = animalcell[m - 1].getchromosomenumber();
            ncromlist = animalcell[n - 1].getcellgen();
            mcromlist = animalcell[m - 1].getcellgen();
            if (ncromnum != mcromnum)
            {
                return false;
            }
            if ()
            for (int i = 0; i < ncromnum; i++)
            {
                genome nn;
                genome mm;
                nn = ncromnum[i].g;
            }




        }


};
*/

int main()
{
    //menu
    cout << "Welcom!" << endl;
    while (1 == 1)
    {
        cout << "Choose number of function from follow list :" << endl;
        int x;
        cout << endl << "Genome functions list :";
        cout << endl << "1) RNA mini jump" << endl << "2) RNA great jump" << endl << "3) RNA reverse jump";
        cout << endl << "4) DNA mini jump" << endl << "5) DNA great jump" << endl << "6) DNA reverse jump" << endl << "7) DNA build" << endl;
        cout << endl << "8) Cell functions list :" << endl << "9) Cell death " << endl << "10) DNA mini jump" << endl << "11) DNA great jump" << endl << "12) DNA reverse jump" << endl << "13) Palindrom" << endl;
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
            cout << endl << "DNA after great jump : " << endl <<  h << endl << l << endl;
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