# Relief Distribution System

1) Need score(total score) Calculation:

     Need score(total score) = (Damage x Families x Route x Flood warning x Medical Need ) ÷ Previous aid

Where,
       Damage: 
              High = 30-points, Medium = 20-points, Low = 10-points

       Families:
                 from 10 to 50 = 2-points, 51-100 = 3-points, 101-150 = 4-points, 151-200 = 5-points

         Route:
                Open = 3-points, Damaged = 5-points
         
      Flood warning:
                      Yes = 5-points, No = 3-points
 
         Medical need:
                       Yes = 2-points, No = 1-point

          Previous aid:
                       Yes = 2 - points, No = 1-point

   Range of Need Score(total score) = 90-7500

2) Decision/Action rules:

                        | Need score(total score)  |  priority level  |      Action     |   Trucks  |  Supply packets|
                              Above 4000                High              Full-Relief        2             50
                              1000-4000                Medium            Standard-Relief     1             30
                               300-999                  Low            Medical-Kit-Only      1             10
                               Below 300             Extremely low       Defer/Monitor       0              0

Resource rule: Before each action the program checks if trucks used ≤ trucks availible and supply used ≤ supply packets availible. If not, the priority level steps one level down and prints the reason.Trucks and supply are subtracted only when the action takes place.

3) Why I designed it this way: 

Damage:
I gave High 30-points because when an area is affected by high damage thier is a lot of destruction in that area because of this many families and homes are affected while medium is 20-points and low is 10-points because areas with these levels have much less destruction than high damage level areas.

Families:
The range of families affested is 10-200 where the first 10-50 families recieve 2-points then 51-100 recieve 3-points then 101-150 recieve 4-points and 151-200 recieve 5-points so more that areas where more families are affected get higher priority.

Route condition:
There are two inputs for route condition open/damaged. when a route is open it will recieve 3-points and when a route is damaged it will recieve 5-points because the areas where route is damaged the people get less resources due to poor route so when distributing relief areas with poor route condition get higher priority.

Flood warning:
If there is a flood warning in that area it recieves 5-points and if there is none then it recieves 3-points this is because areas with flood warning have a higher chance that its resources will be destroyed if a flood comes and it wont have enough food as compared to areas where there is no flood warning.

Medical need:
If there is a medical need in an area it recieves 2-points and if there is no medical need it recieves 1-point because the area with medical needs doubles the need score and the area with no medical needs keeps the need score unchanged.

Previous aid:
If an area recieved a previous aid it will recieve 2-points and if it did not get any previous aid it will get 1-point this is because the area that recieved a previous aid will half the need score and area that did not recieve any previous aid will keep the need score unchanged.

4)Test results:
      |     Requests       |  Damage  |  Families  |  Route  |  Flood warning  |  Medical need  |  Previous aid  |

 R1-Riverside village |   High   |    150    |   Damaged    |     Yes      |         Yes       |        No
 
R2-Hilltop settlement | Medium   |    60     |    Open      |     No       |         No       |         Yes

 R3-Lakeside Camp    |    High     |   90     |    Open      |     Yes      |        Yes       |        Yes
 
R4-Market town      |    Low      |   200     |   Open      |     No       |         No       |         No  

 R5-Bridge colony     |   High     |   40     |   Damaged    |     Yes      |         Yes      |         Yes
 

Test-result-1:
              resources : Trucks = 5 , Supply-packets = 120

R1:
   Need score(total score) = 6000 |  Priority level = High |  Action = Full-Relief   | Truck used = 2| Supply used = 50
             
R2:
Need score(total score) = 270 |  Priority level = Extremely low |  Action = Defer/Monitor  | Truck used = 0| Supply used = 0
           
R3:
Need score(total score) = 2700 |  Priority level = Medium |  Action = Standard-Relief  | Truck used = 1| Supply used = 30
          
R4:
   Need score(total score) = 450 |  Priority level = Low |  Action = Emergency kit only  | Truck used = 1| Supply used = 10
          
R5:
   Need score(total score) = 1500 | Priority level = Medium | Action = Standard-Relief Truck used = 1 | Supply used = 30

Summary:
             Served = 4 | 
           Deferred = 1 | 
        Trucks left = 0 |
Supply-packets left = 0

Screenshots:
<img width="1920" height="1080" alt="Screenshot (115)" src="https://github.com/user-attachments/assets/e23e7709-66c4-4345-ace9-36b3f4dc86c6" />                                  

                                                    Request-1

<img width="1920" height="1080" alt="Screenshot (116)" src="https://github.com/user-attachments/assets/fc273dd4-f284-4e92-9d95-bd67dd024a2c" />

                                                    Request-2

<img width="1920" height="1080" alt="Screenshot (117)" src="https://github.com/user-attachments/assets/5c680d42-795e-4910-9235-a35e25186909" />

                                                    Request-3

<img width="1920" height="1080" alt="Screenshot (118)" src="https://github.com/user-attachments/assets/9b50975c-e13a-4d76-b884-c27c8472441a" />

                                                    Request-4

<img width="1920" height="1080" alt="Screenshot (119)" src="https://github.com/user-attachments/assets/7ef52646-2287-43a1-a438-041e30d713a1" />

                                                    Request-5/Summary


Test-result-2:
              resources : Trucks = 3, Supply-packets = 60

R1:
   Need score(total score) = 6000 | Priority level = High | Action = Full-Relief | Reason = Sufficient resources
           
                    
                   
R2:
   Need score(total score) = 270 | Priority level = Extremely low | Action = Defer/Monitor  |  Reason = Low need
                       
R3:
   Need score(total score) = 2700 |  Priority level = Medium to Low | Action = Emergency kit only  |  Reason = Standard-Relief not possible due to low resources
   
R4:
   Need score(total score) = 450 | Priority level = Low to Extremely Low | Action = Defer/Monitor | Reason = Insufficient resources
                  
R5:
   Need score(total score) = 1500| Priority level = Medium to Low to Extremely low |  Action = Defer/Monitor|  Reason = Insufficient resources
           
Summary:
          |   Served = 2
         |  Deferred = 3
      |  Trucks left = 0
| Supply-packets left = 0

Screenshots:
<img width="1920" height="1080" alt="Screenshot (120)" src="https://github.com/user-attachments/assets/7da8e65b-0acb-4f2b-b189-50f8c792ed71" />

                                                     Request-1

<img width="1920" height="1080" alt="Screenshot (121)" src="https://github.com/user-attachments/assets/2c864d78-d372-4ba9-b5e7-ec7ad29e52f9" />

                                                      Request-2

<img width="1920" height="1080" alt="Screenshot (122)" src="https://github.com/user-attachments/assets/46aa478a-02bd-4e71-b0c5-51473d0d2ef0" />

                                                      Request-3

<img width="1920" height="1080" alt="Screenshot (123)" src="https://github.com/user-attachments/assets/22ad7c17-8418-412e-aeda-f1cb1cfea4da" />

                                                      Request-4

<img width="1920" height="1080" alt="Screenshot (124)" src="https://github.com/user-attachments/assets/126e2cbe-26d0-48e5-9adb-4b21b42dc11b" />

                                                      Request-5

<img width="1920" height="1080" alt="Screenshot (125)" src="https://github.com/user-attachments/assets/0d914a7a-303f-4759-95c9-34627504d162" />

                                                     Summary


5) Names of Group memebers and thier contributions:
     
     |     Name                          |   CMS-ID            |        Contribution  |
    1. Muhammad Talha Saud Khan      |        606424           |         C++ code/README file/Ms word doc
    2. Fahad Hasan                    |       609204            |        C++ code/Flowchart/Ms word doc
    3. Muhammad Abdullah              |        584882            |       Flowchart/Ms word doc

6) Git Repo Link:
                 https://github.com/tk492015-bot/FOCP-ASSIGNMENT-1.0

7) Use of AI:
             We used AI to Understand concepts,Learn new things and Detect Errors in our program.


