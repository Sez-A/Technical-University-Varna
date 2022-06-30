
#include <iostream>
#include<string>
#include<list>
#include <sstream>
#include<conio.h>
#include<fstream>

using namespace std;


// ��������� Player ���� � ����������� �� ����� �� �� ������ ������ ������. �� � ���� �� ������� �������� ������:
struct Player
{
    // ����� � �������.
    int number_in_tournament = 0;
    // ����� � ���������� ���������.
    int number_in_world_rankings = 0;
    //���.
    string first_name = "";
    //�������.
    string second_name = "";
    //�������.
    string country = "";
    // ������ �����.
    int current_points = 0;
    //���� ��������� ����� �����(����).
    int first_places_cnt = 0;

public:
    // ����������� �� ����������� Player � ������ ���������.
    Player(int, int, string, string, string, int, int);
    // ������ �����������.
    Player();

    // ������� ����� ����� ������ � ������� �� ����� �����.
    int get_num_in_tournament() {
        return number_in_tournament;
    }

    // ������� ����� ����� ������ � ���������� ��������� �� ����� �����.
    int get_num_in_world_rankings() {
        return number_in_world_rankings;
    }

    // ������� ����� ����� ����� �� ����� �����.
    string get_first_name() {
        return first_name;
    }

    // ������� ����� ����� ��������� �� ����� �����.
    string get_second_name() {
        return second_name;
    }

    // ������� ����� ����� ���������� �� ���� �� ��� ������� � ����� �����.
    string get_country() {
        return country;
    }

    // ������� ����� ����� ���������� �� ���� ����� �� �������� ����� �� ����� �����.
    int get_current_points() {
        return current_points;
    }

    // ������� ����� ����� ���������� �� ���� ����� ����� �����(����) ��� �������� ����� �����.
    int get_first_places_cnt() {
        return first_places_cnt;
    }



private:

};

// ����������� �� ����������� Player � ������ ���������.
Player::Player(int num_in_tournament, int n_w_rankings, string f_name, string s_name, string c, int c_points, int f_p_cnt)
{
    // ����������� �� ���������, ����� �� ���� �������� �� ������� ���� �� ������ �����������.
    // � ���� ������ ����� �� ���� �������� ��� ����� � ���������� �� ���� ����� � ���� �������� �� �����������.
    number_in_tournament = num_in_tournament;
    number_in_world_rankings = n_w_rankings;
    first_name = f_name;
    second_name = s_name;
    country = c;
    current_points = c_points;
    first_places_cnt = f_p_cnt;
}

// ������ ����������� �� ����������� Player. 
Player::Player() {

}

// ��������� Tournament ���� � �����������, ����� �� ����� ����� ������� � ��� ���� ���� ����:
struct Tournament
{
    // ���� � ���� �� �������, � ����� ����������� ����� ���� ����� � ������������ �� ����.
    list<Player> players;

    // ������������ �� ����������� Tournament.
public:
    Tournament();

    // ��������� set_player ������ ���� ����� �� ������� ���� � �� ������� � ���� �� ����� ���� � ������.
    void set_player(Player p) {

        players.push_back(p);
    }

    // ��������� set_n_players ������ ���� � ������.
    void set_n_players(list<Player> player_list) {

        // ��������� while ������ ������ ������, ����� ��� �������� �� ������� ���� �� ����� ������.
        while (!player_list.empty())
        {
            // ������� ����� �� �������� �� ����� �� ������� ����.
            Player p = player_list.front();

            // ������ ������ �� ����� �� ����� ��� �������� �����
            player_list.pop_front();

            //��������� ������ � ����� ����.
            players.push_back(p);
        }
    }

    // ������� ����� ��� ��������� ����� ���� ���������� ������ ������, ����� ����� ���� "players" �������.
    list<Player> get_data() {
        return players;
    }

    //������� ����� ���� ���� ����� �� "players".
    void pop_player_of_tournament() {
        players.pop_front();
    }

    /* ��������� pop_player_of_index ���� ���� ��������� ����� ���� �������� ����� �� ���� �� ��� ������� �� ������ ������, �����
    ������ �� ������.
    */
    void pop_player_of_index(int m) {
        // ������ �� ��� list, ����� �� ����������, �� �� ������� � ���� ������ ������ ��� ����, ����� ������ �� ������.
        list<Player> new_player_list;
        int i = 1;
        // ������ while ������ ������ ������ "players" �� ������ ������.

        while (!players.empty())
        {
            // ������� �� ����� �� �������� �� players.
            Player p = players.front();
            // ������ �� �� players.
            players.pop_front();

            /* ��� i == m ���� �����, �� ��� �������� ������ ����� � �� �� �������� �  new_player_list, �� �� ����
            � new_player_list �� �� ������ ������ ��� ����, ����� ��� ������ �� ������.
            */
            if (i != m) {
                new_player_list.push_back(p);

            }
            i++;
        }
        // ����������� �� ������ players ������ ������, ����� ��� �������� � new_player_list.
        players = new_player_list;
    }

    /* ��������� set_plyaer_index ����������, �� �� �������� ����� �� ���������� �������.
    ��������� ������ ��� ����������
    m - ��������� �� ����� ������ �� �������� ����� �����
    new_p - ������, ����� �� �������� �� ���� �������.
    */
    void set_player_index(int m, Player new_p) {
        // ������ �� ��� ���� �� Player.
        list <Player> new_player_list;

        /* ���� ���������� �� � ����������, �� �� ����������� �� ���� �� ������ ����� for �����, ����� � ��-������ � ����.
        / �������� �� � players.size() + 1 ������ � ������� ����� �������� N ������ � players ��������� players.size() == N;
        ������ �� ������� ��� ���� ����� � �� �� ���������� ������� �� ������ players.size() + 1.
        */
        int iteration_cnt = players.size() + 1;

        //�������� ���������� �� ��� Player 
        Player temp;

        for (int i = 1; i <= iteration_cnt; i++)
        {
            //��� � new_player_list ����� N + 1 ����� ������� ��� �������� ����� ����� � break-���� �� ������.
            if (new_player_list.size() == iteration_cnt)
                break;


            Player p;

            // �������� �� ���� ���� �������� �� �� �������� �������� � ����� ���� players. 
            if (players.size() != 0) {

                // ������� �� ���� �����.
                p = players.front();

                // ������ �� �� players.
                players.pop_front();

            }

            // ��� i � �������� �� m ����� �� ��� �� ���������, ����� ������ �� ������� ����� �����.
            if (i != m) {

                /* ����������� ���� ��� ���������� ���������� temp ����� �������� ���� ���� ���� ��� ������ ���� �������, �� ���
                �� ��� ��������� player �� ��� �� �� ����� ����� ��-������ � ���� ���� �� ������ ���� � temp ������������.
                ���� ���������� �� ������������ �� ������ ����� � ������� � ������ �����.
                       */
                if (temp.get_country() != ""
                    || temp.get_current_points() != 0
                    || temp.get_first_name() != ""
                    || temp.get_first_places_cnt() != 0
                    || temp.get_num_in_tournament() != 0
                    || temp.get_num_in_world_rankings() != 0
                    || temp.get_second_name() != "") {

                    new_player_list.push_back(temp);
                }

                // �������� � new_player_list ������ ����� ������ �� players.
                if (p.get_country() != ""
                    || p.get_current_points() != 0
                    || p.get_first_name() != ""
                    || p.get_first_places_cnt() != 0
                    || p.get_num_in_tournament() != 0
                    || p.get_num_in_world_rankings() != 0
                    || p.get_second_name() != "") {

                    new_player_list.push_back(p);

                }

            }
            else {
                // ������ ������ ����� � �� �� �� �� ������� ��� �������� ������� ��� ��� ������, ��� ����������� �� temp 
                // ������������ �� ������� ����� p.
                temp = p;
                // i == m ����� ��� �� ��������� ����� ������ �� ������� ����� ����� � �� ��������.
                new_player_list.push_back(new_p);
            }
        }

        // ���������� �� players �������� ������, ����� ��������� ��-���� � new_player_list.
        players = new_player_list;
    }
    // ������� �� ���� �� ������ ������ ������.
    void removeAll() {
        while (!players.empty())
        {
            players.pop_front();
        }
    }

private:

};

// ������ ����������� �� ����������� Tournament.
Tournament::Tournament()
{
}

// ������� �� �������� �� ���� �����

Player addOnePlayer(int cnt) {


    string line;

    // ������� ������� �� "������" ���� �� ������ ����� ���� � 0, � �� �������� ���� � ������ ���.
    int num_in_tournament = 0, num_in_world_rankings = 0;
    string first_name = "", second_name = "", country = "";
    int current_points = 0, first_places_cnt = 0;

    if (cnt == 0)
        cin.ignore();


    cout << "������ ��� �����: " << endl;
    // ��������� �� ���������� �� ������.
    cout << "Number of the player in tournament: ";
    getline(cin, line);
    stringstream converter(line);
    converter >> num_in_tournament;

    cout << "Number in world rankings: ";
    getline(cin, line);
    stringstream converter1(line);
    converter1 >> num_in_world_rankings;
    cout << "First name: ";

    getline(cin, first_name);

    cout << "Last name: ";
    getline(cin, second_name);

    cout << "Country: ";
    getline(cin, country);

    cout << "Current points: ";

    getline(cin, line);
    stringstream converter2(line);
    converter2 >> current_points;

    cout << "First places count: ";
    getline(cin, line);
    stringstream converter3(line);
    converter3 >> first_places_cnt;
    cout << endl;

    // ��������� �� ����� ����� ���� ������������ ���� �������� ���������� �� ������ ����������, ����� ��� �������.
    Player player(num_in_tournament, num_in_world_rankings, first_name, second_name,
        country, current_points, first_places_cnt);

    // ������� ������.
    return player;
}

// ������� �� ��������� �� n �� ���� ������ �������� ��������� int n, ����� � ����� �� �������� ����� ������ �� ���������.
list<Player> add_n_players(int n) {

    list<Player> list_of_players;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        //��������� ���� ����� ���� ��������� addOnePlayer, ����� � ��-����.
        Player player = addOnePlayer(cnt);
        cnt++;
        //�������� ������ � ����� ����.
        list_of_players.push_back(player);
    }
    // ������� ����� �� main ��������� ������ � ��������� �� ����� Tournament set_n_players �� ������� � ����� ������ n-�� ���� ������.
    return list_of_players;
}

// ������� �� ���������� �� ������ �������� ���� ��������� list � ������.
void printer_for_players(list<Player> players_list) {

    // � ���� ������� �� ���������� ��������.
    list<Player>::iterator it;


    for (it = players_list.begin(); it != players_list.end(); it++)
    {


        // ���������� �� ����� ����� ����� �� ����� ������ � �������.
        int number_in_tournament = it->get_num_in_tournament();

        // ���������� �� ����� ����� ����� �� ����� ������ � ���������� ���������.
        int number_in_world_rankings = it->get_num_in_world_rankings();

        // ���������� �� ����� ����� ����� �� ����� �����.
        string first_name = it->get_first_name();

        // ���������� �� ����� ����� ����� �� ����� ���������.
        string second_name = it->get_second_name();

        // ���������� �� ����� ����� ����� �� ����� ���������.
        string country = it->get_country();

        // ���������� �� ����� ����� ����� �� ����� �������� �����.
        int current_points = it->get_current_points();

        // ���������� �� ����� ����� ����� �� ����� ���� �� ����������� ����� �����(����).
        int first_places_cnt = it->get_first_places_cnt();


        // ���������� ������������ �� ������� �����.

        cout << endl;
        cout << "Number in tournament: " << number_in_tournament << endl << "Number in the world rankings:"
            << number_in_world_rankings << endl;
        cout << "First name: " << first_name << endl << "Last name: " << second_name << endl;
        cout << "Country: " << country << endl << "Current points of player: " << current_points << endl;
        cout << "First places count: " << first_places_cnt << endl;

    }
}


// ������� �� ���� �� ����� � ����� ������ ��� � ������ ��� ��� �� ������� ������ � ����� ���� ���-����� ��������� ����.
void compare_players_wons(Tournament tournament) {

    // ������� ������ ������, ����� �������� � �������.
    list <Player> player_list = tournament.get_data();

    // �������� ���������� �� ��� Player
    Player temp;
    // ���� � ����� �� ������ ������ � ���-����� ��������� ����.
    list<Player> players_less_wons;
    temp.first_places_cnt = INT16_MAX;

    // ������ while �����, ������ ��� ������ � player_list.
    while (!player_list.empty())
    {
        // ������� ���� �����.
        Player p = player_list.front();
        // ������ �� �� player.list.
        player_list.pop_front();
        // ����������� ��� �� ������� ����� ���� �� ������ � ��-����� ��� ����� �� ���� �� ���������� ����������
        if (p.get_first_places_cnt() <= temp.get_first_places_cnt()) {
            // ����������� �� temp ������������ �� ������� �����, ������ �������� ���� �� ��-����� � ���� � temp �� ���
            // ���������� �� ������ � ���-����� ��������� ���� �� ���.
            temp = p;

        }

    }

    // ������� � ����� ������ � ���-����� ��������� ���� � �������.
    players_less_wons.push_back(temp);
    // ������� ��� ���� ��� ������ ������ � �������.
    list <Player> sec_pl_list = tournament.get_data();
    // ������ while ������, ������ � sec_pl_list ��� ������.
    while (!sec_pl_list.empty())
    {
        /* ������� ����� �� ����� �� ����������� ���� ���� ��������� ���� �� � ����� �� ���� �� ����������� ���� �� ����� �����,
        ����� �� ���� ��� ���-����� ���� ��������� ����. ��� �� ����� ���� ��������, �� � ������� ��� ������� ������ � �����
        ���� ��������� ���-����� ����.
        */
        Player p = sec_pl_list.front();
        // ������ ������.
        sec_pl_list.pop_front();
        // ����������� ���� ��� ���������� ������� ����� �� � ��������, �� �� �� ������� ���� � ���� ����� ��� ����.
        if (p.get_first_places_cnt() == temp.get_first_places_cnt() && p.get_first_name() != temp.get_first_name())
            // ��� �� �����, �� ��� ����� ����� ���� �� �������� � �����  players_less_wons.
            players_less_wons.push_back(p);
    }

    // ���������� ������ ��� ��� �� ������� ��������.
    printer_for_players(players_less_wons);
}

// ������� �� ���� �� ���������� ������ ������ �� ���������� �������.
void target_country_printer(Tournament tournament, string target_country) {

    // ���� � ������ ������ � �������
    list<Player> players = tournament.get_data();

    // ���� � ����� �� ������� ������ ������, ����� �� �� ���������� �������.
    list<Player> target_country_players;

    while (!players.empty())
    {
        Player player_for_compare = players.front();
        players.pop_front();

        // ������ �������� ��� �� ������� ����� ��������� � ������ ���� ��������� �� ����� ������ �� ���������� ������ ������
        //�������� �� � ����� ���� ��� ������ ���� �� ���� �������.
        if (player_for_compare.get_country() == target_country)
            target_country_players.push_back(player_for_compare);
    }

    // ���������� ��������.
    printer_for_players(target_country_players);
}




// ������� ����� �� �������� ���� �� ���� ����� ����������� � ������� ������ � �������.
bool validate_tournament_num(Tournament& tournament, int num) {
    // ������� ������ ����������� � �������.
    list<Player> players = tournament.get_data();

    // ������ while ����� ������ players ��� ��� ��� �����������.
    while (!players.empty())
    {
        // ������� �����������.
        Player p = players.front();

        // ������ �� �� players.
        players.pop_front();

        /* num � ����������, ����� ���� �� ��������� introduce_new_data_for_player � ���� �������� � ������ ����� �� ������
      � ��� � ������� ��� ����� ����� ����� ������ ������� true � �� �������� ��� ����� ��� ��������� introduce_new_data_for_player.
        */
        if (p.get_num_in_tournament() == num)
            return true;
    }
    // ��� ���� ����� � ���� ����� ����� ������ �� ������ �� ����� ����� ������� false.
    return false;
}

// ������� � ����� ��������� ������ ����� �� ������.
Player introduce_new_data_for_player(Tournament& t) {


    string line;
    int num_in_tournament = 0, num_in_world_rankings = 0;
    string first_name = "", second_name = "", country = "";
    int current_points = 0, first_places_cnt = 0;
    cout << "������ ������ ����� �� ������: " << endl;
    cout << "Number of the player in tournament: ";

    // ��������� ���� ��� ����� �� ���� ������ ��� ����� � �������.
    cin.ignore();
    getline(cin, line);

    // ������������ �� ��� int.
    stringstream converter(line);
    converter >> num_in_tournament;

    /* ��������� validate_tournament_num �� �� ����������, �� ������ ����� �� ������ � ������� ���� �� ��������
    � ���� �� ����� ���� �����. � ������ �� �������� ��������� while ����� ������ �� ������� �������������� �� ��� �����.
    */
    while (validate_tournament_num(t, num_in_tournament))
    {
        cout << "���� � ������� ���������� ����� � ���� ����� ���� �������� ���� �����: ";
        getline(cin, line);
        stringstream converter(line);
        converter >> num_in_tournament;
    }

    cout << "Number in world rankings: ";

    // ��������� ���, ����� �� ���� ������ �� ����� � ���������� ���������.
    getline(cin, line);
    // ������������ �� ��� int.
    stringstream converter1(line);
    converter1 >> num_in_world_rankings;

    cout << "First name: ";
    // ��������� ���� ���.
    getline(cin, first_name);
    // ��������� ���� �������.
    cout << "Last name: ";
    getline(cin, second_name);
    // ��������� ���� �������.
    cout << "Country: ";
    getline(cin, country);


    cout << "Current points: ";
    // ��������� ���, ����� �� ������������ ������ ���� ������ ����� � �������.
    getline(cin, line);
    // ������������ �� ��� int.
    stringstream converter2(line);
    converter2 >> current_points;

    cout << "First places count: ";
    // ��������� ���, ����� �� ������������ ���� �� ������ �� ��������� ����� �����(����).
    getline(cin, line);
    // ������������ ��� int.
    stringstream converter3(line);
    converter3 >> first_places_cnt;
    cout << endl;
    // ������ �� ����� ����� � ������ �� �����.
    Player player(num_in_tournament, num_in_world_rankings, first_name, second_name,
        country, current_points, first_places_cnt);
    return player;
}

// ������� � ����� �� ������� �� ��� ����� ������ �� ������� ���� �����.
void new_data_for_player(Tournament& tournament) {
    // ������� �� ������ ������.
    list<Player> players = tournament.get_data();
    // ��������� ����� �������� 3 � ���� �������� �� �������� ������� �� ������ ����� � �������.
    cout << "�������� �������: ";
    int m;
    cin >> m;

    // ����������� ���� ������� ����� ��� ������ �� � ����������� ��� ��� �� � ��-������ �� players.size(), ����� ��������
    // �� ������� � ����� ������ ����� � players.

    if (m < 0) {
        cout << "������� ����� ��� ������ � ���������: " << endl;
        cout << "���� ��� �� ��� ���������� �� ����������� �������" << endl;
    }

    else  if (m > players.size())
    {

        cout << "������� ����� ��� ������ � ���������: " << endl;
        cout << "� ������� ��� ����: " << players.size() << " �����������" << endl;

    }
    else {



        // ��������� for ����� �� 1(������ �����) ����������� �� m, �� �� ������ ������, ����� ������ �� �� �������� �������.
        for (int i = 1; i <= m; i++)
        {
            // ������� ����� �����.
            Player player = players.front();
            // ������ �� �� players.
            players.pop_front();
            // ��� i � ����� �� m �����, �� ��� ������� ����� �����.
            if (i == m) {

                // �� �������� ���� �� ���� ����� �� �� ������� �����.
                list<Player>list_with_one_player;
                Player player_for_check = player;
                bool checker = player_for_check.get_num_in_tournament() == 0
                    || player_for_check.get_num_in_world_rankings() == 0
                    || player_for_check.get_first_name() == ""
                    || player_for_check.get_second_name() == ""
                    || player_for_check.get_country() == ""
                    || player_for_check.get_current_points() == 0
                    || player_for_check.get_first_places_cnt() == 0;

                // ��� ������� ���������� �����������.
                if (checker) {
                    cout << "��� �������� ���������� �� ���� ���������� ������������ �� ���� � ������� �������� ��� ����!!!" << endl;
                    list_with_one_player.push_back(player_for_check);
                    cout << endl;
                    printer_for_players(list_with_one_player);
                    list_with_one_player.pop_front();

                }

                cout << "�������� ������ �����: " << endl;

                // ������ �� �� ������� ��� ������� �� �����.
                tournament.pop_player_of_index(m);
                // ��������� �� ��������� �� ��������� �� ���� �����.
                Player new_player = introduce_new_data_for_player(tournament);
                // ������� ����� ����� � ������ �� ����� �� ��������� �� ����� �� �������� ��� ������� �� �����.
                tournament.set_player_index(m, new_player);
            }

        }
    }
}

//������� �� ���������� �� ������ ������ � �������.
void printer_all_players(Tournament tournament) {
    // ������ �� ���� � ������ ������, ����� �� � �������.
    list<Player> players = tournament.get_data();
    // ��������� ������ �������, ����� ������� ���� ��������� ���� �� Player � �������� ������������ �� ����� ���� �����.
    printer_for_players(players);
}

// ������� �� ���������� �� ���������� �� ��������� �������.
Player get_P_at_this_index(list<Player> _list, int _i) {

    list<Player>::iterator it = _list.begin();
    _i = _i - 1;
    for (int i = 0; i < _i; i++) {
        ++it;
    }
    return *it;
}

// ������� �� ������ �� ����� �� ��������� �������
list<Player> remove_p_index(list<Player> players, int index, int remove_cnt) {
    list<Player> new_player_list;

    int i = 1;
    /* ���� � remove_cnt �� ������ ������ ��� ������ �� ������ ����� �� ����� ������� � remove_cnt � 0 ���� ��������, �� ������ �� ��� ������ ������ � ������ �� ����
     ����� �� �� ���� ���������, ���� ������ ������ �����  ���� ������ �� ������ ������ �� ����� �������, �� ��� ���� ����� ���� ������ � ����� � � ���� �����
     ��-����� ����� ������ ������� �� � ���� ����� � ������ ����� ������ � ������� � �� ��������� �� ������ �����(����� �� ��������)
    ������� �� ��������� �� ������ � �.�.!
    */
    index = index - remove_cnt;

    if (index == 0) {
        index = 1;
    }

    // ������ while ������ ������ ������ "players" �� ������ ������.
    while (!players.empty())
    {
        // ������� �� ����� �� �������� �� players.
        Player p = players.front();
        // ������ �� �� players.
        players.pop_front();

        /* ��� i == index ���� �����, �� ��� �������� ������ ����� � �� �� �������� �  new_player_list, �� �� ����
        � new_player_list �� �� ������ ������ ��� ����, ����� ��� ������ �� ������.
        */
        if (i != index) {
            new_player_list.push_back(p);

        }
        i++;
    }
    // ����������� �� ������ players ������ ������, ����� ��� �������� � new_player_list.

    return new_player_list;
}

// ������� �� ����� ��������� �� ������ 
list<Player> handmake_duels(list<Player> players, Tournament tournament) {

    // ���� � ����� �� ������� ������ ���������� �� ������ ������ � �� �� �������� �� �������� ����
    list <Player> winners;

    // ���� � ����� �� ������ ����� ����������� (������), �� �� ����� �� ������� ��� �� ��� �� �������� ������.
    list<Player> current_duel;
    int remove_cnt = 0;

    while (!players.empty()) {
        int first_p;
        int second_p;

        cout << endl;
        cout << "�������� ��� ����� � ����� �� �������� ��� ����������� �� �� � ������!" << endl;
        cout << "�������� ����� � ����� �� �������� ������� ���������� �� ������.";
        cin >> first_p;
        cout << "�������� ����� � ����� �� �������� ������� ���������� �� ������.";
        cin >> second_p;

        while (first_p < 0 || first_p > players.size() || second_p < 0 || second_p > players.size())
        {
            // ��� �� �����, �� ������� ����� � ����� ����������� �� �� ������������� ������ ���� �����.
            cout << "������� ����� ��� ������ � ��������� �������� ���� �����: ";
            cin >> first_p;
            cin >> second_p;
        }
        if (first_p == second_p) {
            cout << "�������, ����� ��� ������ ������� ���� � ���� ���������� ���� �������� ���� ����� � ����� �� ������ ������ ���������.";
            cin >> second_p;
        }
        // ������� ������ ����� �� ������
        Player first_player = get_P_at_this_index(players, first_p - remove_cnt);
        // ������� ������ ����� �� ������
        Player second_player = get_P_at_this_index(players, second_p - remove_cnt);
        // ������ �� �� players.
        players = remove_p_index(players, first_p, remove_cnt);
        remove_cnt++;
        players = remove_p_index(players, second_p, remove_cnt);
        remove_cnt++;

        //������� �� � ����� current_duel � �� ��� �� ������� ��� �� ��� �� �������� ������.
        current_duel.push_back(first_player);
        current_duel.push_back(second_player);
        cout << endl;
        cout << "����������� � ���� ������ ��: " << endl;
        printer_for_players(current_duel);
        cout << "������ ����������� �� ������ ���� ������� ����� 1-�������� �� ������ 2-�������� �� ������ ����������: " << endl;
        int num;
        cin >> num;

        // ������� ���������� �� ������� ������
        Player winner_p = get_P_at_this_index(current_duel, num);
        //������� ���������� ��� winners.
        winners.push_back(winner_p);
        current_duel.pop_front();
        current_duel.pop_front();

    }

    // � players ������� ������ ������(������������), ����� ����� ��� winners
    players = winners;
    // ������ ������ ������ �� �������.
    tournament.removeAll();
    // � ������� ���� ����, ����� �� ����������.
    tournament.set_n_players(winners);
    return players;
}

// ������� �� ������
void duels(Tournament tournament) {
    list<Player> players = tournament.get_data();

    list<Player> current_duel;
    list<Player> winners;

    //����������� ���� � players ����� 64 ��� ������ ������, ����� �� �����, �� �������� �� �������� �� 64 ������
    if (players.size() > 64) {
        // ��� ����� �������� 100 ������ ���� � 64 ������ �� ����� ���� 50 ������ � �� �������� for ������ ���� �� 50 ������ ���� 50 ������ ������, ����� ��
        // �������� � ��������.
        int cnt = players.size() / 2;
        // �� ����� ����� ������ ��� ��������� ��� �� �� ������� ��-����� �� 64 ������ � ������ ���������� ����������� ��������� ���� ������ � �������.
        int duel_cnt = 0;
        // ���������� ���� ����� ����� ����������� ��� �������� ���� ��� � ����������.
        for (int i = 1; i <= cnt; i++)
        {
            if (players.size() >= 2) {


                Player first_player = players.front();
                players.pop_front();
                tournament.pop_player_of_tournament();

                Player second_player = players.front();
                players.pop_front();
                tournament.pop_player_of_tournament();

                current_duel.push_back(first_player);
                current_duel.push_back(second_player);
                cout << endl;
                cout << "����������� � ���� ������ ��: " << endl;
                printer_for_players(current_duel);

                cout << "������ ����������� �� ������ ���� ������� ����� 1-�������� �� ������ 2-�������� �� ������ ����������: " << endl;
                int num;
                cin >> num;

                Player winner_p = get_P_at_this_index(current_duel, num);
                winners.push_back(winner_p);
                current_duel.pop_front();
                current_duel.pop_front();
                duel_cnt++;
            }
        }

        // �� ���������� ����������� �� ����� ���� �������� ������� �� �������� ��� �����������.
        while (!players.empty())
        {
            Player p = players.front();
            players.pop_front();
            tournament.pop_player_of_tournament();
            winners.push_back(p);
        }
        // ��� �� �� ������� ��-����� �� 64 ������ � ������ ���������� ����������� ��������� ���� ������ � �������.
        if (duel_cnt < 64) {
            int remainder = 64 - duel_cnt;
            cout << "�� ��������� ���� ���������� ������ � �������, �� �� ��������� ��� 32 ��������" << endl;
            cout << "�� �� ��������� ���� �������� " << remainder << " ����������� � �������!" << endl;
            for (int i = 0; i < remainder; i++)
            {
                Player p = addOnePlayer(i);
                winners.push_back(p);
            }

        }
        // ��������� ��� players ������ ���������� �� 64 ��������.
        players = winners;
    }
    // ������ �� 32 ������.
    //����������� ���� � players ����� 32 ��� ������ ������, ����� �� �����, �� �������� �� �������� �� 32 ������
    if (players.size() > 32 && players.size() <= 64) {
        int cnt_f_32 = players.size() / 2;
        int d_cnt_32 = 0;
        list<Player> winners_32;
        // ���������� ���� ����� ����� ����������� ��� �������� ���� ��� � ����������.
        for (int i = 1; i <= cnt_f_32; i++)
        {
            if (players.size() >= 2) {


                Player first_player = players.front();
                players.pop_front();
                tournament.pop_player_of_tournament();

                Player second_player = players.front();
                players.pop_front();
                tournament.pop_player_of_tournament();

                current_duel.push_back(first_player);
                current_duel.push_back(second_player);
                cout << endl;
                cout << "����������� � ���� ������ ��: " << endl;
                printer_for_players(current_duel);

                cout << "������ ����������� �� ������ ���� ������� ����� 1-�������� �� ������ 2-�������� �� ������ ����������: " << endl;
                int num;
                cin >> num;

                Player winner_p = get_P_at_this_index(current_duel, num);
                winners_32.push_back(winner_p);
                current_duel.pop_front();
                current_duel.pop_front();
                d_cnt_32++;
            }
        }

        // �� ���������� ����������� �� ����� ���� �������� ������� �� �������� ��� �����������.
        while (!players.empty())
        {
            Player p = players.front();
            players.pop_front();
            tournament.pop_player_of_tournament();
            winners_32.push_back(p);
        }
        // ��� �� �� ������� ��-����� �� 32 ������ � ������ ���������� ����������� ��������� ���� ������ � �������.
        if (d_cnt_32 < 32) {
            int remainder = 32 - d_cnt_32;
            cout << "�� ��������� ���� ���������� ������ � �������, �� �� ��������� ��� 16 ��������" << endl;
            cout << "�� �� ��������� ���� �������� " << remainder << " ����������� � �������!" << endl;
            for (int i = 0; i < remainder; i++)
            {
                Player p = addOnePlayer(i);
                winners_32.push_back(p);
            }

        }
        // ������� � players ������ �����������, ����� �� ���������� �� 32 �������� ���� �� ����������� ��� 16 ��������.
        players = winners_32;
        tournament.set_n_players(winners_32);
    }
    // ���� �� 32 ������.

    // ������ �� 16 ������.
    if (players.size() > 16 && players.size() <= 32) {
        int cnt_f_16 = players.size() / 2;
        int d_cnt_16 = 0;
        list<Player> winners_16;
        // ���������� ���� ����� ����� ����������� ��� �������� ���� ��� � ����������.
        for (int i = 1; i <= cnt_f_16; i++)
        {
            if (players.size() >= 2) {


                Player first_player = players.front();
                players.pop_front();
                tournament.pop_player_of_tournament();

                Player second_player = players.front();
                players.pop_front();
                tournament.pop_player_of_tournament();

                current_duel.push_back(first_player);
                current_duel.push_back(second_player);
                cout << endl;
                cout << "����������� � ���� ������ ��: " << endl;
                printer_for_players(current_duel);

                cout << "������ ����������� �� ������ ���� ������� ����� 1-�������� �� ������ 2-�������� �� ������ ����������: " << endl;
                int num;
                cin >> num;

                Player winner_p = get_P_at_this_index(current_duel, num);
                winners_16.push_back(winner_p);
                current_duel.pop_front();
                current_duel.pop_front();
                d_cnt_16++;
            }
        }

        // �� ���������� ����������� �� ����� ���� �������� ������� �� �������� ��� �����������.
        while (!players.empty())
        {
            Player p = players.front();
            players.pop_front();
            tournament.pop_player_of_tournament();
            winners_16.push_back(p);
        }
        // ��� �� �� ������� ��-����� �� 16 ������ � ������ ���������� ����������� ��������� ���� ������ � �������.
        if (d_cnt_16 < 16) {
            int remainder = 16 - d_cnt_16;
            cout << "�� ��������� ���� ���������� ������ � �������, �� �� ��������� ��� 16 ��������" << endl;
            cout << "�� �� ��������� ���� �������� " << remainder << " ����������� � �������!" << endl;
            for (int i = 0; i < remainder; i++)
            {
                Player p = addOnePlayer(i);
                winners_16.push_back(p);
            }

        }

        // ������� ��� players ������ ���������� �� 16 ������ � �� ��������� ��� ������ ��������.
        players = winners_16;
        tournament.set_n_players(winners_16);
    }

    /* ������ ������ ��������� ��������� handmake_duels � ���� �� �������� ����� ���� ������ �� ������ �������� � �� �������
    ������������, ����� �� ��������� ��� ���������� ��������.
    */
    if (players.size() > 8 && players.size() <= 16) {
        players = handmake_duels(players, tournament);
    }

    /* ���������� ������ ��������� ��������� handmake_duels � ���� �� �������� ����� ���� ������ �� ���������� �������� � �� ������� ������������,
    ����� �� ��������� ��� ������������.
    */
    if (players.size() > 4 && players.size() <= 8) {
        players = handmake_duels(players, tournament);
    }
    // ���������� ��������� ��������� handmake_duels � ���� �� �������� ����� ���� ������ �� ������������  � �� ������� ������������, ����� �� �� �� �����.
    if (players.size() > 2 && players.size() <= 4) {
        players = handmake_duels(players, tournament);
    }


    // �����
    if (players.size() == 2) {
        // ���������� ��� �� �����������.
        cout << "����������� � ������� ��: " << endl;
        printer_for_players(players);

        int first_p = 1;
        int second_p = 2;
        int remove_cnt = 0;
        cout << endl;

        Player first_player = get_P_at_this_index(players, first_p - remove_cnt);
        players = remove_p_index(players, first_p, remove_cnt);
        remove_cnt++;
        Player second_player = get_P_at_this_index(players, second_p - remove_cnt);
        players = remove_p_index(players, second_p, remove_cnt);
        remove_cnt++;

        // ������� ������.
        current_duel.push_back(first_player);
        current_duel.push_back(second_player);
        cout << endl;
        cout << "������ ����������� �� ������ ���� ������� ����� 1-�������� �� ������ 2-�������� �� ������ ����������: " << endl;
        int num;
        cin >> num;

        Player winner_p = get_P_at_this_index(current_duel, num);
        list<Player> winner_in_tournament;
        winner_in_tournament.push_back(winner_p);
        cout << "��������� � ������� �: " << endl;
        // ���������� ����������.
        printer_for_players(winner_in_tournament);
        current_duel.pop_front();
        current_duel.pop_front();
    }



}

class player_world_rankings_compare {
public:


    bool operator()(Player& a,
        Player& b)
    {

        // ������� �� ������ ����� ������ � ���������� ��������� � �� ���������� � ������ �� ������ ����� ��� � ��-����� ������� true.
        if (a.get_num_in_world_rankings() < b.get_num_in_world_rankings()) {
            return true;
        }
        // � �������� ������ ������� �������� false.
        return false;
    }
};

void players_sorted_world_rankings_num(Tournament tournament) {

    // ������ �� ���� ���� ������� ������������ �� ������� �� ����������� Tournament ���� ���������
    //get_data() ����� ������� ������ � ������ ������.

    list<Player> players_list = tournament.get_data();

    // ������ �� ����� �� ����� player_wons_compare!
    player_world_rankings_compare cmp;

    //��������� ����� ���� ��� �������� ��� ���� ������ cmp.
    players_list.sort(cmp);

    // ���������� ������ ������ ��� �������� ��� ������ ���� �� ���� ������ � ���-����� � ��������� ���������.
    printer_for_players(players_list);
}

class alphabeticly_sort {
public:


    bool operator()(Player& a,
        Player& b)
    {

        // ������� ����� �� ������ ����� � �� ���������� � ����� �� ������ ��� ������� � ����� ������� ����� �� ������ � ����� ������� � ����� ������� ����� ��
        // ������ ����� ������� true.
        if (a.get_first_name() < b.get_first_name()) {
            return true;
        }
        // � �������� ������ ������� �������� false.
        return false;
    }
};

// ��� ��������� target_country_sorted �� ��������� �������� �� ���������� ������� �� ������� �� ��������� � ������� ���.
void target_country_sorted(Tournament tournament) {

    string target_country;
    cout << "���� �������� �������: ";
    cin >> target_country;

    // ���� � ������ ������ � �������
    list<Player> players = tournament.get_data();

    // ���� � ����� �� ������� ������ ������, ����� �� �� ���������� �������.
    list<Player> target_country_players;

    while (!players.empty())
    {
        Player player_for_compare = players.front();
        players.pop_front();

        // ������ �������� ��� �� ������� ����� ��������� � ������ ���� ��������� �� ����� ������ �� ���������� ������ ������
        //�������� �� � ����� ���� � ������ ���� �� ���� �������.
        if (player_for_compare.get_country() == target_country)
            target_country_players.push_back(player_for_compare);
    }
    alphabeticly_sort cmp;
    // ���������
    target_country_players.sort(cmp);
    // ����������.
    printer_for_players(target_country_players);
}

class t_country_f_places {
public:


    bool operator()(Player& a,
        Player& b)
    {

        // ������� �� ������ ����� ���� ��������� ����� ����� � ���������� � ���� �� ������ ��� �� ��-�����
       // ������� �������� true.
        if (a.get_first_places_cnt() > b.get_first_places_cnt()) {
            return true;
        }
        // � �������� ������ ������� �������� false.
        return false;
    }
};
/* ��� ��������� target_country_first_places_sorter �� ��������� � ���������
��� ������ ������ �� ��������� ������� ������ ���� ��� ��� ��-����� ��������� ����� �����(����)
*/
void target_country_first_places_sorter(Tournament tournament) {
    string target_country;
    cout << "���� �������� �������: ";
    cin >> target_country;

    // ���� � ������ ������ � �������
    list<Player> players = tournament.get_data();

    // ���� � ����� �� ������� ������ ������, ����� �� �� ���������� �������.
    list<Player> target_country_players;

    while (!players.empty())
    {
        Player player_for_compare = players.front();
        players.pop_front();

        // ������ �������� ��� �� ������� ����� ��������� � ������ ���� ��������� �� ����� ������ �� ���������� ������ ������
        //�������� �� � ����� ���� � ������ ���� �� ���� �������.
        if (player_for_compare.get_country() == target_country)
            target_country_players.push_back(player_for_compare);
    }
    t_country_f_places cmp;
    target_country_players.sort(cmp);
    printer_for_players(target_country_players);

}

// ������� �� ��������� �� ������ ����� ��� ���� �� ��������, ����� �� ���� � ���������.
void save_data(Tournament tournament) {
    list<Player> players = tournament.get_data();
    ofstream myfile;
    myfile.open("example.txt");
    int players_cnt = players.size();
    myfile << players_cnt << endl;
    // ��������� ������� �� ����� ����� ��� ����� example.txt
    while (!players.empty())
    {
        Player p = players.front();
        players.pop_front();
        myfile << p.get_num_in_tournament() << endl;
        myfile << p.get_num_in_world_rankings() << endl;
        myfile << p.get_first_name() << endl;
        myfile << p.get_second_name() << endl;
        myfile << p.get_country() << endl;
        myfile << p.get_current_points() << endl;
        myfile << p.get_first_places_cnt() << endl;
    }
    myfile.close();
}
// ������� �� ������ �� �������, ����� �� ���� �������� � example.txt ���� �������� ��� ��� ����� ����� ������ ����� �� ����� ��������� � ��� �� �������� � ���������
// save_data ��� ��� ���������� �� ��������� ���� �� �������� read_data_from_file � ��� � ������� �� �� ������ ����� ������ �� ������� ���.
Tournament read_data_from_file() {
    int t_num;
    int w_r_num;
    string f_name;
    string l_name;
    string country;
    int c_points;
    int f_places_cnt;
    Tournament tournament;
    ifstream infile;
    infile.open("example.txt");
    int iter_cnt;
    infile >> iter_cnt;
    for (int i = 0; i < iter_cnt; i++)
    {
        infile >> t_num;
        infile >> w_r_num;
        infile >> f_name;
        infile >> l_name;
        infile >> country;
        infile >> c_points;
        infile >> f_places_cnt;

        Player player(t_num, w_r_num, f_name, l_name, country, c_points, f_places_cnt);

        tournament.set_player(player);
    }

    return tournament;

}

// ����
void menu() {
    setlocale(LC_ALL, "Bulgarian");
    cout << "                                                   ����" << endl;
    cout << endl;
    cout << "������ ���� �����, �� �� ������� ������� �� ������: " << endl;
    cout << endl;
    cout << "1: �� ��������� �� ��� ����� � �������" << endl;
    cout << endl;
    cout << "2: �� ��������� �� n �� ���� ������: " << endl;
    cout << endl;
    cout << "3: �� ��������� �� ������ ����������� �� ������" << endl;
    cout << endl;
    cout << "4: �� ���������� �� �������� � ���-����� ��������� ����" << endl;
    cout << endl;
    cout << "5: �� ���������� �� �������� �� ���������� �������" << endl;
    cout << endl;
    cout << "6: ���������� �� ����� �� ���������� ��� ��� ������� � �������" << endl;
    cout << endl;
    cout << "7: �� ��������� �� �������� ������ �� ����� �� ������ ������" << endl;
    cout << endl;
    cout << "8: �� ��������� �� ����������� ��������� �� ����� � ���������� ���������" << endl;
    cout << endl;
    cout << "9: �� ��������� �� ����������� �� ���������� ������� ��������� �� ������� ���" << endl;
    cout << endl;
    cout << "10: �� ��������� �� ����������� �� ���������� ������� ��������� �� ���� ��������� ���� � ��������� ���";
    cout << endl;
    cout << endl;
    cout << "11: �� ��������� �� ������� � ���������� ��� ����" << endl;
    cout << endl;
    cout << "12: �� ��������� �� ���������� ����� �� �������� ���������� �� ����������" << endl;
    cout << endl;
}

int main()
{
    // ���������� �� ��� Tournament � ����� �� �� ����������� ������ ������.
    Tournament tournament;

    setlocale(LC_ALL, "Bulgarian");

    while (true)
    {
        // ����.
        menu();

        list<Player> players;
        Player player;
        int n;
        string str;

        // ����� � ������ ����.

       // ������� ���������� command �� ��� int �� ����� ����� �� �������� ������������ �� ���� str ��-����, �� �� ����� �� �������
       // ��� swtich.
        int command;
        // ��������� ����� ���.
        cout << "������ �����, �� �� ������� ������� �� ������ ��� end �� ���� �� ���������! ";
        cin >> str;



        // ����������� ���� ���� �� � "end" ��� � ��� ������ �������� ���������.
        if (str == ("end"))
            break;

        // ��� �� � end ������������ �� ��� int � ������� � �����, ����� ��� �� ������� �� ������ � ���������� ����������.
        stringstream converter(str);
        converter >> command;

        cout << endl;
        // �� ��� �� ������� ����� �������� ������ �� �������� ���� �� ��������� ���� ����� ��� N-�� ���� ������ � �.�.
        switch (command)
        {
        case 1:
            player = addOnePlayer(0);

            tournament.set_player(player);
            break;

        case 2:

            cout << "n = ";
            cin >> n;
            players = add_n_players(n);
            tournament.set_n_players(players);
            break;

        case 3:
            printer_all_players(tournament);
            break;
        case 4:

            compare_players_wons(tournament);
            break;

        case 5:
            cout << "������ �������: ";

            cin >> str;

            target_country_printer(tournament, str);
            break;

        case 6:
            cout << "������ �� ��������� ������� �� ��������� ����� ����� " << endl;
            cout << "T����� �� �������� �����, �� �� �������� ������  ����� ����� ������ �� ��������� ";
            cout << "�������� 1 - �� ������ ����� 2 - �� ������ � n - �� n-��� �����" << endl;
            new_data_for_player(tournament);
            break;

        case 7:
            duels(tournament);
            break;

        case 8:
            players_sorted_world_rankings_num(tournament);
            break;

        case 9:
            target_country_sorted(tournament);
            break;

        case 10:
            target_country_first_places_sorter(tournament);
            break;

        case 11:
            save_data(tournament);
            break;

        case 12:
            tournament = read_data_from_file();
            break;

        default:
            break;
        }



    }
    return 0;
}