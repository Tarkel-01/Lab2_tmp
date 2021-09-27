//By Alexander Romanenko

#include "Airplane.h"

void SortForTask(Airplane a[], int Size) {
    Airplane tmp;
    int index;
    for (int i = 0; i < Size - 1; i++) {
        index = i;
        for (int j = i + 1; j < Size; j++) {
            if (a[index].GetPecent() < a[j].GetPecent())
                index = j;
        }
        tmp = a[i];
        a[i] = a[index];
        a[index] = tmp;
    }

}
int main()
{
    setlocale(LC_ALL, "Russian");
    
    Airplane airplane[3];
    
    airplane[0].SetModel("Airbus-CS100");
    airplane[0].SetAirline("Донецк-Ростов");
    airplane[0].SetYearOfIssue(2013);
    airplane[0].SetCapacity(125);

    airplane[1].SetModel("Airbus-A310");
    airplane[1].SetAirline("Донецк-Казань");
    airplane[1].SetYearOfIssue(1983);
    airplane[1].SetCapacity(279);

    airplane[2].SetModel("Боинг-777");
    airplane[2].SetAirline("Донецк-Волгоград");
    airplane[2].SetYearOfIssue(1995);
    airplane[2].SetCapacity(400);

    Airplane *a = new Airplane("Airbus-CS100", "Донецк-Москва", 2013, 125);

    airplane[0].Move();
    airplane[1].Move();
    airplane[2].Move();

    std::cout << "BEFORE" << std::endl << std::endl;
    airplane[0].PrintInfo();
    airplane[1].PrintInfo();
    airplane[2].PrintInfo();

    SortForTask(airplane, 3);

    std::cout << "AFTER" << std::endl << std::endl;
    airplane[0].PrintInfo();
    airplane[1].PrintInfo();
    airplane[2].PrintInfo();

    airplane[0].serialize();
    airplane[1].serialize();
    airplane[2].serialize();
    
    delete a;
}
