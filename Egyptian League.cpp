#include <iostream>
#include <string>
using namespace std;

class TeamNode
{
public:
    int id;
    string name;
    string president;
    TeamNode* next;

    TeamNode()
    {
        id = 0;
        name = "";
        president = "";
        next = NULL;
    }
};

class PlayerNode
{
public:
    int id;
    string name;
    string team;
    string position;
    int age;
    double salary;
    PlayerNode* next;

    PlayerNode()
    {
        id = 0;
        name = "";
        team = "";
        position = "";
        age = 0;
        salary = 0.0;
        next = NULL;
    }
};

class TeamList
{
public:
    TeamNode* head;

    TeamList()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        if (head == NULL) {
            return true;
        }
        else {
            return false;
        }
    }


    void addTeam(int id, string name, string president)
    { 
        TeamNode* newnteam = new TeamNode();  //بعمل نود جديدة
        newnteam->id = id;
        newnteam->name = name;
        newnteam->president = president;
        newnteam->next = head; // بيربط النود الجديدة بالقديم
        head = newnteam;    // بيخلي الجديدة هي أول الليست
    }
    void displayTeams()
    {
        if (isEmpty() == true) {
            cout << "there is no teams";
        }
        else {
            TeamNode* temp = head;
            while (temp != NULL)
            {
                cout << "ID: " << temp->id << " | Name: " << temp->name
                    << " | President: " << temp->president << endl;
                temp = temp->next;
            }
        }
    }

    TeamNode* searchTeam(int id) {
        if (isEmpty() == true) {
            cout << "there is no teams";
        }
        else {
            TeamNode* temp = head;
            while (temp != NULL)
            {
                if (temp->id == id) {
                    return temp;
                }
                temp = temp->next;
            }
        }
    }

    void updateTeam(int id, string newName, string newPresident)
    {
        TeamNode* temp = searchTeam(id);
        if (temp != NULL)
        {
            temp->name = newName;
            temp->president = newPresident;
            cout << "Team Updated Successfully\n";
        }
        else
            cout << "Team Not Found\n";
    }
};
// end of the team linked list

// start of the team list
class PlayerList
{
public:
    PlayerNode* head;
    PlayerList()
    {
        head = NULL;
    }
    bool isEmpty()
    {
        if (head == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
    void addPlayer(int id, string name, string team, string position, int age, double salary)
    {
        PlayerNode* newnode = new PlayerNode();
        newnode->id = id;
        newnode->name = name;
        newnode->team = team;
        newnode->position = position;
        newnode->age = age;
        newnode->salary = salary;

        newnode->next = head;
        head = newnode;
    }

    void displayPlayers()
    {
        PlayerNode* temp = head;
        while (temp != NULL)
        {
            cout << "ID: " << temp->id << endl;
            cout << " Name: " << temp->name << endl;
            cout << " Team: " << temp->team << endl;
            cout << " Position: " << temp->position << endl;
            cout << " Age: " << temp->age << endl;
            cout << "  Salary: " << temp->salary << endl;

            temp = temp->next;
        }
    }
    PlayerNode* searchPlayer(string name)
    {
        if (isEmpty() == true) {
            cout << "the list is empty" << endl;
        }
        else {
            PlayerNode* temp = head;
            while (temp != NULL)
            {
                if (temp->name == name) {
                    return temp;
                }
                else {
                    temp = temp->next;
                }
            }
            cout << "player not found" << endl;
            return NULL;
        }
    }

    void deletePlayer(string name)
    {
        if (isEmpty())
        {
            cout << "Empty Player List\n";
            return;
        }

        if (head->name == name) // if player is the frist node
        {
            PlayerNode* temp = head;
            head = head->next;
            delete temp;
            cout << "Player Removed\n";
            return;
        }

        PlayerNode* temp = head; 
        while (temp->next != NULL && temp->next->name != name) // لو اللي بعدي مش آخر واحدة ولسه مش هي اللي بدوّر عليها… أمشي للّي بعدها
            temp = temp->next;

        if (temp->next == NULL)
        {
            cout << "Player Not Found\n"; // لو وصل للآخر وملاقاش اللاعب
            return;
        }

        PlayerNode* delnode = temp->next; // امسك اللاعب اللي هيتشال
        temp->next = temp->next->next; // وصّل اللي قبل باللي بعده
        delete delnode;   // امسح اللاعب من الميموري

        cout << "Player Removed\n";
    }
}; int main()
{
    TeamList teams; //object
    PlayerList players; //object

    int choice;

    while (true)
    {
        cout << "\n===== EGYPTIAN LEAGUE MANAGEMENT =====\n";
        cout << "1. Add New Team\n";
        cout << "2. Display Teams\n";
        cout << "3. Search Team by ID\n";
        cout << "4. Update Team Information\n";
        cout << "5. Add New Player\n";
        cout << "6. Remove a Player\n";
        cout << "7. Display Players\n";
        cout << "8. Search Player by Name\n";
        cout << "9. Exit Program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Add new team
        {
            int id;
            string name, president;
            cout << "Enter Team ID: ";
            cin >> id;
            cout << "Enter Team Name: ";
            cin >> name;
            cout << "Enter Team President: ";
            cin >> president;

            teams.addTeam(id, name, president);
            break;
        }

        case 2: // Display teams
            teams.displayTeams();
            break;

        case 3: // Search team by ID
        {
            int id;
            cout << "Enter Team ID to search: ";
            cin >> id;
            TeamNode* t = teams.searchTeam(id);
            if (t != NULL)
                cout << "Team Found: " << t->name << " | President: " << t->president << endl;
            else
                cout << "Team Not Found\n";
            break;
        }

        case 4: // Update team info
        {
            int id;
            string newName, newPresident;
            cout << "Enter Team ID to update: ";
            cin >> id;
            cout << "Enter New Team Name: ";
            cin >> newName;
            cout << "Enter New President: ";
            cin >> newPresident;

            teams.updateTeam(id, newName, newPresident);
            break;
        }

        case 5: // Add new player
        {
            int id, age;
            double salary;
            string name, team, position;
            cout << "Enter Player ID: ";
            cin >> id;
            cout << "Enter Player Name: ";
            cin >> name;
            cout << "Enter Team Name: ";
            cin >> team;
            cout << "Enter Position: ";
            cin >> position;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Salary: ";
            cin >> salary;

            players.addPlayer(id, name, team, position, age, salary);
            break;
        }

        case 6: // Remove a player
        {
            string name;
            cout << "Enter Player Name to remove: ";
            cin >> name;
            players.deletePlayer(name);
            break;
        }

        case 7: // Display players
            players.displayPlayers();
            break;
        case 8: // Search player by name
        {
            string name;
            cout << "Enter Player Name to search: ";
            cin >> name; // name is primary key 
            PlayerNode* p = players.searchPlayer(name);
            if (p != NULL)
                cout << "Player Found: ID: " << p->id << " | Team: " << p->team
                << " | Position: " << p->position << " | Age: " << p->age
                << " | Salary: " << p->salary << endl;
            break;
        }

        case 9: // Exit
            cout << "Exiting Program...\n";
            system("pause");
            return 0;

        default:
            cout << "Invalid Choice!\n";
        }

        system("pause");
    }

    return 0;
}