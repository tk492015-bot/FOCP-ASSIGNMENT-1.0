#include<iostream>//header file for input output stream
#include<string>//header file for string
using namespace std;//namespace for standard library

int main()//main function
{
    int trucks = 5, supply_packets = 120, served = 0, deferred = 0;//initializing variables
    //trucks and supply_packets are the resources available for distribution and are fixed, served and deferred are counters to check how many requests are accepted and how many are deferred
    int requests;//variable to store number of requests

    cout << "\n\n\t\t Relief Supply Distribution System \n\n";//title of the program
    cout << "\n\n HOW MANY REQUESTS DO YOU WANT TO ENTER? : ";//asking user how many requests they want to enter
    cin >> requests;//taking input from user

    if (requests <= 0)//checking if the number of requests is less than or equal to 0
    {
        cout << "\nENTER ONLY POSITIVE NUMBER\n ";//display an error message
        return 0;//exit the program
    }

    for (int i = 1; i <= requests; i++)//loop to process each request
    {
        string damage_level, route_condition, flood_warning, help_gain;
        string priority_level, request_location, medical_need;//variables to store answers

        int num_people, trucks_used = 0, supply = 0;//variables for families affected and resources used
        int d_score = 0, r_score = 0, f_score = 0, h_score = 0;
        int p_score = 0, total_score = 0, mn_score = 0;//variables used to calculate the score

        cout << "\n\n request number " << i << "\n\n";//display the current request number
        cout << "Enter request location " << 'R' << i << " : ";//ask for the request location
        getline(cin >> ws, request_location);//store the location

        cout << "\tWHAT IS THE DAMAGE LEVEL? (low, high, medium): ";//ask about damage level
        cin >> damage_level;//store the damage level

        while (damage_level != "low" && damage_level != "Low" &&
            damage_level != "LOW" && damage_level != "l" &&
            damage_level != "L" && damage_level != "medium" &&
            damage_level != "Medium" && damage_level != "MEDIUM" &&
            damage_level != "m" && damage_level != "M" &&
            damage_level != "high" && damage_level != "High" &&
            damage_level != "HIGH" && damage_level != "h" &&
            damage_level != "H")
        {
            cout << "Invalid damage level. Enter low, medium, or high: ";//ask again if the answer is invalid
            cin >> damage_level;//store the new answer
        }

        cout << "\n\tHOW MANY FAMILIES ARE AFFECTED? : ";//ask how many families are affected
        cin >> num_people;//store the number of families

        while (num_people < 10 || num_people > 200)//check that the number is between 10 and 200
        {
            cout << "ENTER NUMBER between 10 and 200: ";//ask for a number in the valid range
            cin >> num_people;//store the new number
        }

        cout << "\n\tWHAT IS THE ROUTE CONDITION? (open/damaged): ";//ask about the route condition
        cin >> route_condition;//store the route condition

        while (route_condition != "open" && route_condition != "Open" &&
            route_condition != "OPEN" && route_condition != "o" &&
            route_condition != "O" && route_condition != "damaged" &&
            route_condition != "Damaged" && route_condition != "DAMAGED" &&
            route_condition != "damage" && route_condition != "Damage" &&
            route_condition != "DAMAGE" && route_condition != "d" &&
            route_condition != "D")
        {
            cout << "Invalid route. Enter open or damaged: ";//ask again if the answer is invalid
            cin >> route_condition;//store the new answer
        }

        cout << "\n\tDID YOU RECEIVE ANY FLOOD WARNING? (yes/no): ";//ask about a flood warning
        cin >> flood_warning;//store the answer

        while (flood_warning != "yes" && flood_warning != "Yes" &&
            flood_warning != "YES" && flood_warning != "y" &&
            flood_warning != "Y" && flood_warning != "no" &&
            flood_warning != "No" && flood_warning != "NO" &&
            flood_warning != "n" && flood_warning != "N")
        {
            cout << "Invalid answer. Enter yes or no: ";//ask again if the answer is invalid
            cin >> flood_warning;//store the new answer
        }

        cout << "\n\tIS THERE ANY MEDICAL NEED? (yes/no): ";//ask whether medical help is needed
        cin >> medical_need;//store the answer

        while (medical_need != "yes" && medical_need != "Yes" &&
            medical_need != "YES" && medical_need != "y" &&
            medical_need != "Y" && medical_need != "no" &&
            medical_need != "No" && medical_need != "NO" &&
            medical_need != "n" && medical_need != "N")
        {
            cout << "Invalid answer. Enter yes or no: ";//ask again if the answer is invalid
            cin >> medical_need;//store the new answer
        }

        cout << "\n\tDID YOU RECEIVE ANY PREVIOUS AID? (yes/no): ";//ask whether previous aid was received
        cin >> help_gain;//store the answer

        while (help_gain != "yes" && help_gain != "Yes" &&
            help_gain != "YES" && help_gain != "y" &&
            help_gain != "Y" && help_gain != "no" &&
            help_gain != "No" && help_gain != "NO" &&
            help_gain != "n" && help_gain != "N")
        {
            cout << "Invalid answer. Enter yes or no: ";//ask again if the answer is invalid
            cin >> help_gain;//store the new answer
        }

        if (damage_level == "low" || damage_level == "L" ||
            damage_level == "l" || damage_level == "LOW" ||
            damage_level == "Low")//check for low damage and assign its score
        {
            d_score = 10;//score for low damage
        }
        else if (damage_level == "high" || damage_level == "H" ||
            damage_level == "h" || damage_level == "HIGH" ||
            damage_level == "High")//check for high damage and assign its score
        {
            d_score = 30;//score for high damage
        }
        else//the validated remaining damage level is medium
        {
            d_score = 20;//score for medium damage
        }

        if (route_condition == "open" || route_condition == "O" ||
            route_condition == "o" || route_condition == "OPEN" ||
            route_condition == "Open")//check whether the route is open
        {
            r_score = 3;//score for an open route
        }
        else//the validated remaining route condition is damaged
        {
            r_score = 5;//score for a damaged route
        }

        if (flood_warning == "yes" || flood_warning == "Y" ||
            flood_warning == "y" || flood_warning == "YES" ||
            flood_warning == "Yes")//check whether there is a flood warning
        {
            f_score = 5;//score for yes
        }
        else//the validated remaining answer is no
        {
            f_score = 3;//score for no
        }

        if (medical_need == "yes" || medical_need == "Y" ||
            medical_need == "y" || medical_need == "YES" ||
            medical_need == "Yes")//check whether medical help is needed
        {
            mn_score = 2;//score for yes
        }
        else//the validated remaining answer is no
        {
            mn_score = 1;//score for no
        }

        if (help_gain == "yes" || help_gain == "Y" ||
            help_gain == "y" || help_gain == "YES" ||
            help_gain == "Yes")//check whether previous aid was received
        {
            h_score = 2;//score for yes
        }
        else//the validated remaining answer is no
        {
            h_score = 1;//score for no
        }

        if (num_people >= 10 && num_people <= 50)//check if the number of families is between 10 and 50
        {
            p_score = 2;//score for 10 to 50
        }
        else if (num_people <= 100)//check if the number of families is between 51 and 100
        {
            p_score = 3;//score for 51 to 100
        }
        else if (num_people <= 150)//check if the number of families is between 101 and 150
        {
            p_score = 4;//score for 101 to 150
        }
        else//the number of families is between 151 and 200
        {
            p_score = 5;//score for more than 150
        }

        total_score = d_score * r_score * f_score * p_score * mn_score / h_score;//calculate the total score
        cout << "\n\nTotal Score : " << total_score << "\n\n";//display the total score

        if (total_score < 300)//check if the total score is less than 300
        {
            cout << "\n\npriority level is EXTREMELY LOW\n\n";//display the priority level
            priority_level = "EXTREMELY LOW";//store the priority level
        }
        else if (total_score < 1000)//check if the total score is between 300 and 999
        {
            cout << "\n\npriority level is LOW\n\n";//display the priority level
            priority_level = "LOW";//store the priority level
        }
        else if (total_score <= 4000)//check if the total score is between 1000 and 4000
        {
            cout << "\n\npriority level is MEDIUM\n\n";//display the priority level
            priority_level = "MEDIUM";//store the priority level
        }
        else//the total score is greater than 4000
        {
            cout << "\n\npriority level is HIGH\n\n";//display the priority level
            priority_level = "HIGH";//store the priority level
        }

        if (priority_level == "HIGH")//check if priority is high and assign resources
        {
            trucks_used = 2;//assign two trucks for high priority
            supply = 50;//assign 50 supply packets

            if (trucks >= trucks_used && supply_packets >= supply)//check if enough resources are available
            {
                cout << "\n\nSelected Action : Full Relief\n\n";//display the selected action
                trucks = trucks - trucks_used;//subtract the trucks used
                cout << "\n\nYOUR PRIORITY LEVEL IS HIGH, SO 2 TRUCKS WILL BE USED\n\n";//display the allocation message
                cout << "\n\n YOU NEED " << supply << " SUPPLY PACKETS\n\n";//display the supply amount
                supply_packets = supply_packets - supply;//subtract the supply used
                served++;//increase the accepted-request count
            }
            else//not enough resources for high-priority allocation
            {
                cout << "\n\nNot enough resources for high priority.\n";//display a shortage message
                trucks_used = 0;//reset trucks used
                supply = 0;//reset supply used
                cout << "\n\nChanging priority level to Medium\n\n";//display the downgrade message
                priority_level = "MEDIUM";//change priority to medium
            }
        }

        if (priority_level == "MEDIUM")//check if priority is medium and assign resources
        {
            trucks_used = 1;//assign one truck
            supply = 30;//assign 30 supply packets

            if (trucks >= trucks_used && supply_packets >= supply)//check if enough resources are available
            {
                cout << "\n\nSelected Action : Standard Relief\n\n";//display the selected action
                trucks = trucks - trucks_used;//subtract the trucks used
                cout << "\n\nYOUR PRIORITY LEVEL IS MEDIUM, SO 1 TRUCK WILL BE USED\n\n";//display the allocation message
                cout << "\n\n YOU NEED " << supply << " SUPPLY PACKETS\n\n";//display the supply amount
                supply_packets = supply_packets - supply;//subtract the supply used
                served++;//increase the accepted-request count
            }
            else//not enough resources for medium-priority allocation
            {
                cout << "\n\nNot enough resources for medium priority.\n";//display a shortage message
                trucks_used = 0;//reset trucks used
                supply = 0;//reset supply used
                cout << "\n\nChanging priority level to Low\n\n";//display the downgrade message
                priority_level = "LOW";//change priority to low
            }
        }

        if (priority_level == "LOW")//check if priority is low and assign resources
        {
            trucks_used = 1;//assign one truck
            supply = 10;//assign 10 supply packets

            if (trucks >= trucks_used && supply_packets >= supply)//check if enough resources are available
            {
                cout << "\n\nSelected Action : Emergency Kit Only\n\n";//display the selected action
                cout << "\n\nYOU NEED " << supply << " SUPPLY PACKETS\n\n";//display the supply amount
                trucks = trucks - trucks_used;//subtract the trucks used
                supply_packets = supply_packets - supply;//subtract the supply used
                served++;//increase the accepted-request count
            }
            else//not enough resources for low-priority allocation
            {
                cout << "\n\nNot enough resources for low priority.\n";//display a shortage message
                trucks_used = 0;//reset trucks used
                supply = 0;//reset supply used
                cout << "\n\nChanging priority level to Extremely Low\n\n";//display the downgrade message
                priority_level = "EXTREMELY LOW";//change priority to extremely low
            }
        }

        if (priority_level == "EXTREMELY LOW")//check if priority is extremely low
        {
            cout << "\n\nSelected Action : Defer/Monitor\n\n";//display the selected action
            trucks_used = 0;//no trucks are used
            supply = 0;//no supplies are used
            cout << "\n\nYOUR REQUEST IS DEFERRED\n\n";//display the deferred message
            deferred++;//increase the deferred-request count
        }

        cout << "\n\nTrucks used : " << trucks_used << "\n\n";//display the number of trucks used
        cout << "\n\nSupply used : " << supply << "\n\n";//display the supply used
        cout << "\n\nThere are " << trucks << " trucks left\n\n";//display remaining trucks
        cout << "\n\nThere are " << supply_packets << " supply packets left\n\n";//display remaining supplies
    }//end of the for loop

    cout << "\n\nTotal requests entered : " << requests << "\n\n";//display the number of requests entered
    cout << "\n\nTotal requests accepted : " << served << "\n\n";//display the number of accepted requests
    cout << "\n\nTotal requests deferred/not accepted : " << deferred << "\n\n";//display the number of deferred requests

    return 0;//exit the program
}//end of main
