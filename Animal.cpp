#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Cell.h>
#include <vector>

using namespace std;

class Animal : public cell
{
private:
    cell animalcell;
    int animalchromnumber;
public:
    void getanimal()
    {
        cell t;
        t.chromosomecin();
        animalcell = t;
        animalchromnumber = t.getchromosomenumber();
    }
    cell getanimalcell()
    {
        return animalcell;
    }
    void setanimalcell(cell x)
    {
        animalcell = x;
    }
    double Animalps(Animal n, Animal m)
    {
        cell nn, mm;
        nn = n.getanimalcell();
        mm = m.getanimalcell();
        int x = nn.getchromosomenumber();
        int y = mm.getchromosomenumber();
        vector <genome> k;
        vector <genome> l;
        k = nn.getcellgen();
        l = mm.getcellgen();
        if (x != y)
        {
            return -1;
        }
        if (x == y)
        {

            double percent = 0;
            for (int i = 0; i < x; i++)
            {
                double sum = 0;
                string dnak = k[i].getDNA();
                string dnal = l[i].getDNA();
                int f = size(dnak) / 2;
                for (int j = 0; j < f; j++)
                {
                    if (dnak[j] == dnal[j] && dnak[j + f] == dnal[j + f])
                    {
                        sum++;
                    }
                }
                double t = (sum / f) * 100;
                percent = percent + t;
            }
            double r = percent / x;

            return r;
        }
    }
    friend bool operator == (const Animal& n, const Animal& m)
    {
        cell nn, mm;
        nn = n.animalcell;
        mm = m.animalcell;
        int x = nn.getchromosomenumber();
        int y = mm.getchromosomenumber();
        vector <genome> k;
        vector <genome> l;
        k = nn.getcellgen();
        l = mm.getcellgen();
        if (x != y)
        {
            return false;
        }
        if (x == y)
        {
            int sum = 0;
            int percent = 0;
            for (int i = 0; i < x; i++)
            {
                string dnak = k[i].getDNA();
                string dnal = l[i].getDNA();
                int f = size(dnak) / 2;
                for (int j = 0; j < f; j++)
                {
                    if (dnak[i] == dnal[i] && dnak[i + f] == dnal[i + f])
                    {
                        sum++;
                    }
                }
                double t = (sum / f) * 100;
                percent = percent + t;
            }
            double r = percent / x;
            if (r <= 70)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

    }
    cell Animalar(Animal fatherr)
    {
        cell child;
        cell father = fatherr.getanimalcell();
        vector <genome> childvec;
        vector <genome> fathervec;
        fathervec = father.getcellgen();
        int l = father.getchromosomenumber();
        int maxtekrari = (l * 3) / 10;
        int tekr = 0;
        int i = 0;
        int  t = l / 2;
        int tt = 0;
        while (i < l)
        {
            if (tekr == maxtekrari && tt == t)
            {
                childvec.push_back(fathervec[i]);
            }
            if (tekr != maxtekrari && tt == t)
            {
                srand(time(0));
                int y = rand();
                y = y % 2;
                if (y == 0)
                {
                    childvec.push_back(fathervec[i]);
                }
                if (y == 1)
                {
                    childvec.push_back(fathervec[i]);
                    childvec.push_back(fathervec[i]);
                    tekr++;
                    i++;
                }
            }
            if (tekr == maxtekrari && tt != t)
            {
                srand(time(0));
                int y = rand();
                y = y % 2;
                if (y == 0)
                {
                    childvec.push_back(fathervec[i]);
                }
                if (y == 1)
                {
                    tt++;
                }
            }
            if (tekr != maxtekrari && tt != t)
            {
                srand(time(0));
                int y = rand();

                y = y % 3;
                cout << y; //-----debug
                if (y == 0)
                {
                    childvec.push_back(fathervec[i]);
                }
                if (y == 1)
                {
                    childvec.push_back(fathervec[i]);
                    childvec.push_back(fathervec[i]);
                    tekr++;
                    i++;
                }
                if (y == 2)
                {
                    tt++;
                }
            }
            i++;
        }

        child.setcellgen(childvec);
        child.setchromosomenumber(l);
        return child;
    }

    friend cell operator + (const Animal& fatherr, const Animal& motherr)
    {
        Animal fatherl;
        Animal motherl;

        cell father = fatherl.Animalar(fatherr);
        cell mother = motherl.Animalar(motherr);

        //------------------------------------------------
        cell child;
        vector <genome> childvec;
        vector <genome> fathervec;
        vector <genome> mothervec;
        fathervec = father.getcellgen();
        mothervec = mother.getcellgen();
        int l = father.getchromosomenumber();
        int fathgenful = l / 2;
        int fathnumgen = 0;
        int mothgenful = l / 2;
        int mothnumgen = 0;
        int i = 0;
        while (i < l)
        {
            if (fathnumgen >= fathgenful)
            {
                childvec.push_back(mothervec[i]);
            }
            if (mothnumgen >= mothgenful)
            {
                childvec.push_back(fathervec[i]);
            }
            i++;
            if (fathnumgen < fathgenful && mothnumgen < mothgenful)
            {
                srand(time(0));
                int u = rand();
                int h = u % 2;
                if (h == 0)
                {
                    childvec.push_back(fathervec[i]);
                    fathnumgen++;
                }
                if (h == 1)
                {
                    childvec.push_back(mothervec[i]);
                    mothnumgen++;
                }
            }
        }
        child.setcellgen(childvec);
        child.setchromosomenumber(l);
        return child;
    }


    void Animalcellsdeath()
    {
        animalcell.celldeath();
    }

};
// end Animal class
