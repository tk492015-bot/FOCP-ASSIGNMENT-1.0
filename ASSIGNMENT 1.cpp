#include<iostream>
#include<string>
using namespace std;
int main()
{
    int trucks = 5, supply_packets = 120, served = 0,  deferred = 0;
    int requests;

    cout << "\n\n\t\t Releif Supply Distribution System \n\n";
    cout << "\n\n HOW MANY REQUESTS DO YOU WANT TO ENTER? : ";
    cin >> requests;
    if (requests <= 0)
    {
        cout << "ENTER POSITIVE NUMBER ";
        return 0;
    }
    for (int i = 1; i <= requests; i++)
    {
        string damage_level, route_condition, flood_warning, help_gain, priority_level, request_location, medical_need;
        int num_people, trucks_used, supply;
        int d_score = 0, r_score = 0, f_score = 0, h_score = 0, p_score = 0, total_score = 0, mn_score = 0;
        cout << "\n\n request number " << i << "\n\n";
        cout << "Enter request location " << 'R' << i << " : ";
        getline(cin>> ws,request_location);
        cout << "\tWHAT IS THE DAMAGE LEVEL?(low,high,medium) : ";
        cin >> damage_level;
        cout << "\n\tHOW MANY FAMILIES ARE AFFECTED? : ";
        cin >> num_people;
        if (num_people < 10 || num_people>200)
        {
            cout << "ENTER NUMBER between 10 and 200: ";
            return 0;
        }
        cout << "\n\tWHAT IS THE ROUTE CONDITION?(open/damaged) : ";
        cin >> route_condition;
        cout << "\n\t Did YOU RECEIVE ANY FLOOD WARNING?(yes/no): ";
        cin >> flood_warning;
        cout << "\n\t IS THERE ANY MEDICAL NEED?(yes/no) : ";
        cin >> medical_need;
        cout << "\n\t Did YOU RECEIVE ANY Previous Aid?(yes/no) : ";
        cin >> help_gain;

        if (damage_level == "low" || damage_level == "L" || damage_level == "l" || damage_level == "LOW"  || damage_level == "Low")
        {
            d_score = 10;
        }
        else if (damage_level == "high" || damage_level == "H" || damage_level == "h" || damage_level == "HIGH"|| damage_level == "High")
        {
            d_score = 30;
        }
        else if (damage_level == "medium" || damage_level == "M" || damage_level == "m" || damage_level == "MEDIUM" || damage_level == "med" || damage_level == "MED" || damage_level == "Medium")
        {
            d_score = 20;
        }
        else
        {
            cout << "\n\n INVALID DAMAGE LEVEL \n\n";
            return 0;
        }
        if (route_condition == "open" || route_condition == "O" || route_condition == "o" || route_condition == "OPEN" || route_condition == "Open")
        {
            r_score = 3;
        }
        else if (route_condition == "damaged" || route_condition == "D" || route_condition == "d" || route_condition == "DAMAGED" || route_condition == "damage" || route_condition == "DAMAGE" || route_condition == "Damage" || route_condition == "Damaged")
        {
            r_score = 5;
        }
        else
        {
            cout << "\n\n INVALID ROUTE CONDITION \n\n";
            return 0;
        }
        if (flood_warning == "yes" || flood_warning == "Y" || flood_warning == "y" || flood_warning == "YES" || flood_warning == "Yes")
        {
            f_score = 5;
        }
        else if (flood_warning == "no" || flood_warning == "N" || flood_warning == "n" || flood_warning == "NO" || flood_warning == "No")
        {
            f_score = 3;
        }
        else
        {
            cout << "\n\n INVALID FLOOD WARNING ANSWER  \n\n";
            return 0;
        }
        if (medical_need == "yes" || medical_need == "Y" || medical_need == "y" || medical_need == "YES" || medical_need == "Yes")
        {
            mn_score = 2;
        }
        else if (medical_need == "no" || medical_need == "N" || medical_need == "n" || medical_need == "NO" || medical_need == "No")
        {
            mn_score = 1;
        }
        else
        {
            cout << "\n\n INVALID MEDICAL NEED ANSWER  \n\n";
            return 0;
        }
        if (help_gain == "yes" || help_gain == "Y" || help_gain == "y" || help_gain == "YES" || help_gain == "Yes")
        {
            h_score = 2;
        }
        else if (help_gain == "no" || help_gain == "N" || help_gain == "n" || help_gain == "NO" || help_gain == "No")
        {
            h_score = 1;
        }
        else
        {
            cout << "\n\n INVALID HELP GAIN ANSWER  \n\n";
            return 0;
        }
        if (num_people >= 10 && num_people <= 50)
        {
            p_score = 2;
        }
        else if (num_people > 50 && num_people <= 100)
        {
            p_score = 3;
        }
        else if (num_people > 100 && num_people <= 150)
        {
            p_score = 4;
        }
        else
        {
            p_score = 5;
        }
        total_score = d_score * r_score * f_score * p_score * mn_score / h_score;
        cout << "\n\nTotal Score : " << total_score << "\n\n";
        if (total_score < 300)
        {
            cout << "\n\npriority level is EXTREMELY LOW\n\n";
            priority_level = "EXTREMELY LOW";
        }
        else if (total_score >= 300 && total_score <1000)
        {
            cout << "\n\npriority level is LOW\n\n";
            priority_level = "LOW";
        }
        else if (total_score >= 1000 && total_score <= 4000)
        {
            cout << "\n\npriority level is MEDIUM\n\n";
            priority_level = "MEDIUM";
        }
        else
        {
            cout << "\n\npriority level is HIGH\n\n";
            priority_level = "HIGH";
        }
        
        if (priority_level == "HIGH")
        {
           
            trucks_used = 2;
            supply = 50;
            if (trucks >= trucks_used && supply_packets >= supply)
            {
                cout << "\n\nSelected Action : Full Relief\n\n";
                trucks = trucks - trucks_used;
                cout << "\n\nYOUR PRIORITY LEVEL IS HIGH, SO 2 TRUCKS WILL BE USED FOR SUPPLY DISTRIBUTION\n\n";
                cout << "\n\n YOU NEED  " << supply << " SUPPLY PACKETS\n\n";
                supply_packets = supply_packets - supply;
                served++;
            }
            else
            {
                cout << "\n\nYOUR PRIORITY LEVEL IS HIGH, BUT THERE ARE NOT ENOUGH RESOURCES AVAILABLE FOR DISTRIBUTION\n\n";
                trucks_used = 0;
                supply = 0;
                cout << "\n\nChanging Priority level to Medium\n\n";
                priority_level = "MEDIUM";
            }

        }
        if (priority_level == "MEDIUM")
        {
            cout << "\n\nSelected Action : Standard Relief\n\n";
            trucks_used = 1;
            supply = 30;
            if (trucks >= trucks_used && supply_packets >= supply)
            {
                trucks = trucks - trucks_used;
                cout << "\n\nYOUR PRIORITY LEVEL IS MEDIUM, SO 1 TRUCK WILL BE USED FOR SUPPLY DISTRIBUTION\n\n";
                cout << "\n\n YOU NEED  " << supply << " SUPPLY PACKETS\n\n";
                supply_packets = supply_packets - supply;
                served++;
            }
            else
            {
                cout << "\n\nYOUR PRIORITY LEVEL IS MEDIUM, BUT THERE ARE NOT ENOUGH RESOURCES AVAILABLE FOR DISTRIBUTION\n\n";
                trucks_used = 0;
                supply = 0;
                cout << "\n\nChanging Priority level to LOW\n\n";
                priority_level = "LOW";
            }

        }
        if (priority_level == "LOW" )
        {
            cout << "\n\nSelected Action : Emergency Kit Only\n\n";
            trucks_used = 1;
            supply = 10;
            if (trucks >= trucks_used && supply_packets >= supply)
            {
                cout << "\n\nYOUR PRIORITY LEVEL IS LOW, SO 1 TRUCK WILL BE USED FOR SUPPLY DISTRIBUTION\n\n";
                cout << "\n\n YOU NEED  " << supply << " SUPPLY PACKETS\n\n";
                trucks = trucks - trucks_used;
                supply_packets = supply_packets - supply;
                served++;
            }
            else
            {
                cout << "\n\nYOUR PRIORITY LEVEL IS  LOW, BUT THERE ARE NOT ENOUGH RESOURCES AVAILIBLE FOR DISTRIBUTION\n\n";
                trucks_used = 0;
                supply = 0;
                cout << "\n\nChanging Priority level to EXTREMELY LOW\n\n";
                priority_level = "EXTREMELY LOW";
            }
        }
        if (priority_level == "EXTREMELY LOW" )
        {
            cout << "\n\nSelected Action : Defer/Monitor\n\n";
            trucks_used = 0;
            supply = 0;
            cout << "\n\n YOUR REQUEST IS DEFERRED \n\n";
            deferred++;
        }
        cout << "\n\n Trucks used : " << trucks_used << "\n\n";
        cout << "\n\n Supply used : " << supply << "\n\n";
        cout << "\n\n THERE ARE " << trucks << " TRUCKS LEFT FOR SUPPLY DISTRIBUTION\n\n";
        cout << "\n\n THERE ARE " << supply_packets << " SUPPLY PACKETS LEFT FOR SUPPLY DISTRIBUTION\n\n";
        
    }
    cout << "\n\n Total requests entered : " << requests << "\n\n";
    cout << "\n\nTotal requests accepted : " << served << "\n\n";
    cout << "\n\nTotal requests deffered/not accepted : " << deferred << "\n\n";
    return 0;
}