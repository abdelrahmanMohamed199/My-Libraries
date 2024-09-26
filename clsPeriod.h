#pragma once
#include "clsDate.h"

class clsPeriod
{

public:

    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate EndDate)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;

    }

    static bool areTheyOverlap(clsPeriod period1, clsPeriod period2)
    {
        return !(clsDate::IsDate1BeforeDate2(period1.EndDate, period2.StartDate)
            || clsDate::IsDate1AfterDate2(period1.StartDate, period2.EndDate));
    }


    bool IsOverLapWith(clsPeriod Period2)
    {
        return areTheyOverlap(*this, Period2);
    }

    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();


        cout << "Period End: ";
        EndDate.Print();


    }

};


