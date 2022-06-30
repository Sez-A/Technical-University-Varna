
#include <iostream>
#include<string>
#include<list>
#include <sstream>
#include<conio.h>
#include<fstream>

using namespace std;


// Структура Player това е структурата от която ще си правим нашите играчи. Тя в себе си съдържа следните полета:
struct Player
{
    // Номер в турнира.
    int number_in_tournament = 0;
    // Номер в световната ранглиста.
    int number_in_world_rankings = 0;
    //Име.
    string first_name = "";
    //Фамилия.
    string second_name = "";
    //Държава.
    string country = "";
    // Текущи точки.
    int current_points = 0;
    //Брой спечелени първи места(купи).
    int first_places_cnt = 0;

public:
    // Конструктор на структурата Player с всички параметри.
    Player(int, int, string, string, string, int, int);
    // Празен конструктор.
    Player();

    // Функция която връща номера в турнира на даден играч.
    int get_num_in_tournament() {
        return number_in_tournament;
    }

    // Функция която връща номера в световната ранглиста на даден играч.
    int get_num_in_world_rankings() {
        return number_in_world_rankings;
    }

    // Функция която връща името на даден играч.
    string get_first_name() {
        return first_name;
    }

    // Функция която връща фамилията на даден играч.
    string get_second_name() {
        return second_name;
    }

    // Функция която връща информация за това от коя държава е даден играч.
    string get_country() {
        return country;
    }

    // Функция която връща информация за това колко са текущите точки на даден играч.
    int get_current_points() {
        return current_points;
    }

    // Функция която връща информация за това колко първи места(купи) има спечелни даден играч.
    int get_first_places_cnt() {
        return first_places_cnt;
    }



private:

};

// Конструктор на структурата Player с всички параметри.
Player::Player(int num_in_tournament, int n_w_rankings, string f_name, string s_name, string c, int c_points, int f_p_cnt)
{
    // Присвояване на стойности, които са били подадени от външния свят на нашият конструктор.
    // И така нашият играч ще бъде изграден със данни в зависимост от това какво е било подадено от потребителя.
    number_in_tournament = num_in_tournament;
    number_in_world_rankings = n_w_rankings;
    first_name = f_name;
    second_name = s_name;
    country = c;
    current_points = c_points;
    first_places_cnt = f_p_cnt;
}

// Празен конструктор на структурата Player. 
Player::Player() {

}

// Структура Tournament това е структурата, която се явява тенис турнира и има само едно поле:
struct Tournament
{
    // Това е лист от плейъри, в който съхраняваме всеки един играч и информацията за него.
    list<Player> players;

    // Конструктора на структурата Tournament.
public:
    Tournament();

    // Функцията set_player приема един играч от външния свят и го поставя в края на нашия лист с играчи.
    void set_player(Player p) {

        players.push_back(p);
    }

    // Функцията set_n_players приема лист с играчи.
    void set_n_players(list<Player> player_list) {

        // Завъртаме while циъкла докато листът, който сме получили от външния свят не стане празен.
        while (!player_list.empty())
        {
            // Вземаме играч от началото на листа от външния свят.
            Player p = player_list.front();

            // Махаме играча от листа от който сме получили отвън
            player_list.pop_front();

            //Поставяме играча в нашия лист.
            players.push_back(p);
        }
    }

    // Функция която при извикване връща като информация всички играчи, които нашия лист "players" съдържа.
    list<Player> get_data() {
        return players;
    }

    //Функция която маха един играч от "players".
    void pop_player_of_tournament() {
        players.pop_front();
    }

    /* Функцията pop_player_of_index маха един определен играч като получава номер за това на коя позиция се намира играча, който
    искаме да махнем.
    */
    void pop_player_of_index(int m) {
        // Правим си нов list, който ще изпозлваме, за да запишем в него всички играчи без този, който искаме да махнем.
        list<Player> new_player_list;
        int i = 1;
        // Въртим while цикъла докато нашите "players" не станат празни.

        while (!players.empty())
        {
            // Вземаме си играч от началото на players.
            Player p = players.front();
            // Махаме го от players.
            players.pop_front();

            /* Ако i == m това значи, че сме намерили нашият играч и НЕ го добавяме в  new_player_list, за да може
            в new_player_list да са всички играчи без този, който сме искали да махнем.
            */
            if (i != m) {
                new_player_list.push_back(p);

            }
            i++;
        }
        // Присвояваме на нашите players всички играчи, които сме записали в new_player_list.
        players = new_player_list;
    }

    /* Функцията set_plyaer_index изпозлваме, за да поставим играч на определена позиция.
    Функцията приема два параметъра
    m - позицията на която исакме да поставим нашия играч
    new_p - играча, който ще поставим на тази позиция.
    */
    void set_player_index(int m, Player new_p) {
        // Правим си нов лист от Player.
        list <Player> new_player_list;

        /* Тази променлива ще я изпозлваме, за да проверяваме до кога да въртим нашия for цикъл, който е по-надолу в кода.
        / Избираме да е players.size() + 1 защото в момента имаме примерно N играчи в players съответно players.size() == N;
        понеже ще добавим още един играч и то на определена позиция ни трябва players.size() + 1.
        */
        int iteration_cnt = players.size() + 1;

        //Временна променлива от тип Player 
        Player temp;

        for (int i = 1; i <= iteration_cnt; i++)
        {
            //Ако в new_player_list имаме N + 1 значи успешно сме добавили нашия играч и break-ваме от цикъла.
            if (new_player_list.size() == iteration_cnt)
                break;


            Player p;

            // Проверка за това дали случайно не са свършили играчите в нашия лист players. 
            if (players.size() != 0) {

                // Вземаме си един играч.
                p = players.front();

                // Махаме го то players.
                players.pop_front();

            }

            // Ако i е различно от m значи не сме на позицията, която искаме да добавим нашия играч.
            if (i != m) {

                /* Проверяваме дали във временната променлива temp имаме записано поне едно нещо ако нямаме това ознвача, че още
                не сме присвоили player на нея ще го видим малко по-надолу в кода защо го правим това с temp променливата.
                Чрез проверката се застраховаме да нямаме играч в списъка с празни данни.
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

                // Добавяме в new_player_list играча който взехме от players.
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
                // Понеже взехме играч и за да не го загубим при следващо вземане ако има такова, тук присвояваме на temp 
                // информацията за текущия играч p.
                temp = p;
                // i == m значи сме на позицията която искаме да добавим нашия играч и го добавяме.
                new_player_list.push_back(new_p);
            }
        }

        // Присояваме на players всичките играчи, които добавихме по-горе в new_player_list.
        players = new_player_list;
    }
    // Функция за това да махнем всички играчи.
    void removeAll() {
        while (!players.empty())
        {
            players.pop_front();
        }
    }

private:

};

// Празен конструктор на структурата Tournament.
Tournament::Tournament()
{
}

// Функция за добавяне на еидн играч

Player addOnePlayer(int cnt) {


    string line;

    // Данните отначло са "празни" като за целите числа това е 0, а за низовете това е празен низ.
    int num_in_tournament = 0, num_in_world_rankings = 0;
    string first_name = "", second_name = "", country = "";
    int current_points = 0, first_places_cnt = 0;

    if (cnt == 0)
        cin.ignore();


    cout << "Въведи нов играч: " << endl;
    // Въвеждане на информация за играча.
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

    // Формираме си нашия играч чрез конструктора като подаваме стойността на всички променливи, които сме прочели.
    Player player(num_in_tournament, num_in_world_rankings, first_name, second_name,
        country, current_points, first_places_cnt);

    // Връщаме играча.
    return player;
}

// Функция за формиране на n на брой играчи получава параметър int n, който е броят на играчите които искаме да формираме.
list<Player> add_n_players(int n) {

    list<Player> list_of_players;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        //Формираме един играч чрез функцията addOnePlayer, която е по-горе.
        Player player = addOnePlayer(cnt);
        cnt++;
        //Добавяме играча в нашия лист.
        list_of_players.push_back(player);
    }
    // Връщаме листа на main функцията където с функцията от класа Tournament set_n_players ще добавим в нашия турнир n-на брой играчи.
    return list_of_players;
}

// Функция за принтиране на играчи получава като параметър list с играчи.
void printer_for_players(list<Player> players_list) {

    // В тази фунцкия ще използваме итератор.
    list<Player>::iterator it;


    for (it = players_list.begin(); it != players_list.end(); it++)
    {


        // Достъпваме на нашия текущ играч от листа номера в турнира.
        int number_in_tournament = it->get_num_in_tournament();

        // Достъпваме на нашия текущ играч от листа номера в световната ранглиста.
        int number_in_world_rankings = it->get_num_in_world_rankings();

        // Достъпваме на нашия текущ играч от листа името.
        string first_name = it->get_first_name();

        // Достъпваме на нашия текущ играч от листа фамилията.
        string second_name = it->get_second_name();

        // Достъпваме на нашия текущ играч от листа държавата.
        string country = it->get_country();

        // Достъпваме на нашия текущ играч от листа текущите точки.
        int current_points = it->get_current_points();

        // Достъпваме на нашия текущ играч от листа броя на спечелените първи места(купи).
        int first_places_cnt = it->get_first_places_cnt();


        // Принтираме информацията за текущия играч.

        cout << endl;
        cout << "Number in tournament: " << number_in_tournament << endl << "Number in the world rankings:"
            << number_in_world_rankings << endl;
        cout << "First name: " << first_name << endl << "Last name: " << second_name << endl;
        cout << "Country: " << country << endl << "Current points of player: " << current_points << endl;
        cout << "First places count: " << first_places_cnt << endl;

    }
}


// Функция за това да видим в нашия турнир кой е играча или ако са няколко играча с равен брой най-малко спечелени купи.
void compare_players_wons(Tournament tournament) {

    // Вземаме всички играчи, които участват в турнира.
    list <Player> player_list = tournament.get_data();

    // Временна променлива от тип Player
    Player temp;
    // Лист в който ще сложим играча с най-малко спечелени купи.
    list<Player> players_less_wons;
    temp.first_places_cnt = INT16_MAX;

    // Въртим while цикъл, докато има играчи в player_list.
    while (!player_list.empty())
    {
        // Вземаме един играч.
        Player p = player_list.front();
        // Махаме го от player.list.
        player_list.pop_front();
        // Проверяваме ако на текущия играч броя на купите е по-малък или равен на тези на временната променлива
        if (p.get_first_places_cnt() <= temp.get_first_places_cnt()) {
            // Присвояваме на temp информацията за текущия играч, защото неговите купи са по-малко и така в temp ще има
            // информация за играча с най-малко спечелени купи до тук.
            temp = p;

        }

    }

    // Слагаме в листа играча с най-малко спечелени купи в турнира.
    players_less_wons.push_back(temp);
    // Вземаме още един път всички играчи в турнира.
    list <Player> sec_pl_list = tournament.get_data();
    // Въртим while цикъла, докато в sec_pl_list има играчи.
    while (!sec_pl_list.empty())
    {
        /* Вземаме играч на който ще проверяваме дали броя спечелени купи не е равен на броя на спечелените купи на нашия играч,
        който до тука има най-малък брой спечелени купи. Ако са равни това означава, че в турнира има няколко играча с равен
        брой спечелени най-малко купи.
        */
        Player p = sec_pl_list.front();
        // Махаме играча.
        sec_pl_list.pop_front();
        // Проверяваме като при проверката гледаме името да е различно, за да не запишем един и същи играч два пъти.
        if (p.get_first_places_cnt() == temp.get_first_places_cnt() && p.get_first_name() != temp.get_first_name())
            // Ако се окаже, че има такъв играч също го добавяме в листа  players_less_wons.
            players_less_wons.push_back(p);
    }

    // Принтираме играча или ако са няколко играчите.
    printer_for_players(players_less_wons);
}

// Функция за това да принтираме всички играчи от определена държава.
void target_country_printer(Tournament tournament, string target_country) {

    // Лист с всички играчи в турнира
    list<Player> players = tournament.get_data();

    // Лист в който ще съберем всички играчи, които са от определена държава.
    list<Player> target_country_players;

    while (!players.empty())
    {
        Player player_for_compare = players.front();
        players.pop_front();

        // Правим проверка ако на текущия играч държавата е същата като държавата от която искаме да принтираме всички играчи
        //Добавяме го в нашия лист със играчи само от тази държава.
        if (player_for_compare.get_country() == target_country)
            target_country_players.push_back(player_for_compare);
    }

    // Принтираме играчите.
    printer_for_players(target_country_players);
}




// Функция която ще валидира това да няма двама състезателя с еднакви номера в турнира.
bool validate_tournament_num(Tournament& tournament, int num) {
    // Вземаме всички състезатели в турнира.
    list<Player> players = tournament.get_data();

    // Въртим while цикъл докато players все още има състезатели.
    while (!players.empty())
    {
        // Вземаме състезателя.
        Player p = players.front();

        // Махаме го от players.
        players.pop_front();

        /* num е променлива, която идва от функцията introduce_new_data_for_player и това всъшност е новият номер на играча
      и ако в турнира има играч чийто номер съпада връщаме true и ще поискаме нов номер във функцията introduce_new_data_for_player.
        */
        if (p.get_num_in_tournament() == num)
            return true;
    }
    // Ако няма играч с този номер който искаме да сложим на нашия играч връщаме false.
    return false;
}

// Функция в която въвеждаме новите данни на играча.
Player introduce_new_data_for_player(Tournament& t) {


    string line;
    int num_in_tournament = 0, num_in_world_rankings = 0;
    string first_name = "", second_name = "", country = "";
    int current_points = 0, first_places_cnt = 0;
    cout << "Въведи новите данни на играча: " << endl;
    cout << "Number of the player in tournament: ";

    // Прочитаме един низ който ще бъде нашият нов номер в турнира.
    cin.ignore();
    getline(cin, line);

    // Конвертираме го към int.
    stringstream converter(line);
    converter >> num_in_tournament;

    /* Извикваме validate_tournament_num за да валидираме, че новият номер на играча в турнира няма да съвпадне
    с този на някой друг играч. В случай че съвпадне завъртаме while циъкл докато не получим удовлетворяващ за нас номер.
    */
    while (validate_tournament_num(t, num_in_tournament))
    {
        cout << "Вече в турнира съществува играч с този номер моля въведете ново число: ";
        getline(cin, line);
        stringstream converter(line);
        converter >> num_in_tournament;
    }

    cout << "Number in world rankings: ";

    // Прочитаме низ, който ще бъде новият ни номер в световната ранглиста.
    getline(cin, line);
    // Конвертираме го към int.
    stringstream converter1(line);
    converter1 >> num_in_world_rankings;

    cout << "First name: ";
    // Прочитаме ново име.
    getline(cin, first_name);
    // Прочитаме нова фамилия.
    cout << "Last name: ";
    getline(cin, second_name);
    // Прочитаме нова държава.
    cout << "Country: ";
    getline(cin, country);


    cout << "Current points: ";
    // Прочитаме низ, който ще представлява нашите нови текущи точки в турнира.
    getline(cin, line);
    // Конвертираме го към int.
    stringstream converter2(line);
    converter2 >> current_points;

    cout << "First places count: ";
    // Прочитаме низ, който ще представлява броя на новите ни спечелени първи места(купи).
    getline(cin, line);
    // Конвертираме към int.
    stringstream converter3(line);
    converter3 >> first_places_cnt;
    cout << endl;
    // Правим си нашия играч с новите му данни.
    Player player(num_in_tournament, num_in_world_rankings, first_name, second_name,
        country, current_points, first_places_cnt);
    return player;
}

// Фунцкия в която ще изберем на кой играч искаме да зададем нови данни.
void new_data_for_player(Tournament& tournament) {
    // Вземаме си нашите играчи.
    list<Player> players = tournament.get_data();
    // Въвеждаме число примерно 3 и така избираме да променим данните на третия играч в турнира.
    cout << "Въведете числото: ";
    int m;
    cin >> m;

    // Проверяваме дали числото което сме въвели не е отрицателно или пък не е по-голямо от players.size(), което всъшност
    // ни показва и колко играчи имаме в players.

    if (m < 0) {
        cout << "Числото което сте въвели е невалидно: " << endl;
        cout << "Няма как да има съзтезател на отрицателна позиция" << endl;
    }

    else  if (m > players.size())
    {

        cout << "Числото което сте въвели е невалидно: " << endl;
        cout << "В турнира има само: " << players.size() << " съзтезателя" << endl;

    }
    else {



        // Завъртаме for цикъл от 1(първия играч) включително до m, за да вземем играча, който искаме да му променим данните.
        for (int i = 1; i <= m; i++)
        {
            // Вземаме текущ играч.
            Player player = players.front();
            // Махаме го от players.
            players.pop_front();
            // Ако i е равно на m значи, че сме открили нашия играч.
            if (i == m) {

                // Ще проверим дали на този играч не му липсват данни.
                list<Player>list_with_one_player;
                Player player_for_check = player;
                bool checker = player_for_check.get_num_in_tournament() == 0
                    || player_for_check.get_num_in_world_rankings() == 0
                    || player_for_check.get_first_name() == ""
                    || player_for_check.get_second_name() == ""
                    || player_for_check.get_country() == ""
                    || player_for_check.get_current_points() == 0
                    || player_for_check.get_first_places_cnt() == 0;

                // Ако липсват принтираме съобщението.
                if (checker) {
                    cout << "Има липсваща информация за този съзтезател информацията за него в момента изглежда ето така!!!" << endl;
                    list_with_one_player.push_back(player_for_check);
                    cout << endl;
                    printer_for_players(list_with_one_player);
                    list_with_one_player.pop_front();

                }

                cout << "Въведете новите данни: " << endl;

                // Махаме го от турнира със старите му данни.
                tournament.pop_player_of_index(m);
                // Извикваме си функцията за въвеждане на нови данни.
                Player new_player = introduce_new_data_for_player(tournament);
                // Слагаме нашия играч с новите му данни на позицията от която го махнахме със старите му данни.
                tournament.set_player_index(m, new_player);
            }

        }
    }
}

//Функция за принтиране на всички играчи в турнира.
void printer_all_players(Tournament tournament) {
    // Правим си лист с всички играчи, които са в турнира.
    list<Player> players = tournament.get_data();
    // Извикваме нашата функция, която получва като параметър лист от Player и принтира информацията за всеки един играч.
    printer_for_players(players);
}

// Функция за получаване на състезател от определна позиция.
Player get_P_at_this_index(list<Player> _list, int _i) {

    list<Player>::iterator it = _list.begin();
    _i = _i - 1;
    for (int i = 0; i < _i; i++) {
        ++it;
    }
    return *it;
}

// Функция за махане на играч от определна позиция
list<Player> remove_p_index(list<Player> players, int index, int remove_cnt) {
    list<Player> new_player_list;

    int i = 1;
    /* Това с remove_cnt го правим понеже ако искаме да махнем играч от първа позиция и remove_cnt е 0 това означава, че досега не сме махали играчи и всички са така
     както са си били подредени, нека махнем първия играч  сега искаме да махнем играча на втора позиция, но ние вече имаме едно махане и листа е с един играч
     по-малко тоест всички позиции са с една назад и втория играч реално в момента е на позицията на първия играч(който го махнахме)
    третият на позицията на втория и т.н.!
    */
    index = index - remove_cnt;

    if (index == 0) {
        index = 1;
    }

    // Въртим while цикъла докато нашите "players" не станат празни.
    while (!players.empty())
    {
        // Вземаме си играч от началото на players.
        Player p = players.front();
        // Махаме го от players.
        players.pop_front();

        /* Ако i == index това значи, че сме намерили нашият играч и НЕ го добавяме в  new_player_list, за да може
        в new_player_list да са всички играчи без този, който сме искали да махнем.
        */
        if (i != index) {
            new_player_list.push_back(p);

        }
        i++;
    }
    // Присвояваме на нашите players всички играчи, които сме записали в new_player_list.

    return new_player_list;
}

// Функция за ръчно съставяне на двубои 
list<Player> handmake_duels(list<Player> players, Tournament tournament) {

    // лист в който ще запишем всчики победители от текущи двубои и ще се класират на следващо ниво
    list <Player> winners;

    // лист в който ще сложим двама състезателя (двубой), за да можем да изберем кой от тях ще продължи напред.
    list<Player> current_duel;
    int remove_cnt = 0;

    while (!players.empty()) {
        int first_p;
        int second_p;

        cout << endl;
        cout << "Въведете две числа с които да изберете кои съзтезатели ще са в двубой!" << endl;
        cout << "Въведете число с което да изберете първият съзтезател за двубоя.";
        cin >> first_p;
        cout << "Въведете число с което да изберете вторият съзтезател за двубоя.";
        cin >> second_p;

        while (first_p < 0 || first_p > players.size() || second_p < 0 || second_p > players.size())
        {
            // Ако се окаже, че числото което е въвел потребителя не ни удовлетворява искаме ново число.
            cout << "Числото което сте въвели е невалидно въведете ново число: ";
            cin >> first_p;
            cin >> second_p;
        }
        if (first_p == second_p) {
            cout << "Числата, които сте въвели избират един и същи съзтезател моля въведете ново число с което да избере втория съзтезтел.";
            cin >> second_p;
        }
        // Вземаме първия играч за двубоя
        Player first_player = get_P_at_this_index(players, first_p - remove_cnt);
        // Вземаме втория играч за двубоя
        Player second_player = get_P_at_this_index(players, second_p - remove_cnt);
        // Махаме ги от players.
        players = remove_p_index(players, first_p, remove_cnt);
        remove_cnt++;
        players = remove_p_index(players, second_p, remove_cnt);
        remove_cnt++;

        //Слагаме ги в листа current_duel и от тук ще изберем кой от тях ще продължи напред.
        current_duel.push_back(first_player);
        current_duel.push_back(second_player);
        cout << endl;
        cout << "Участниците в този двубой са: " << endl;
        printer_for_players(current_duel);
        cout << "Избери побетдителя от двубоя като въведеш число 1-отговаря за първия 2-отговаря за втория съзтезател: " << endl;
        int num;
        cin >> num;

        // Вземаме победителя от текущия двубой
        Player winner_p = get_P_at_this_index(current_duel, num);
        //Слагаме победителя във winners.
        winners.push_back(winner_p);
        current_duel.pop_front();
        current_duel.pop_front();

    }

    // В players слагаме всички играчи(победителите), които имаме във winners
    players = winners;
    // Махаме всички играчи от турнира.
    tournament.removeAll();
    // И слагаме само тези, които са победители.
    tournament.set_n_players(winners);
    return players;
}

// Функция за двубои
void duels(Tournament tournament) {
    list<Player> players = tournament.get_data();

    list<Player> current_duel;
    list<Player> winners;

    //Проверяваме дали в players имаме 64 или повече играчи, което ще значи, че двубоите ще започнат от 64 финали
    if (players.size() > 64) {
        // Ако имаме примерно 100 играча това е 64 финали но имаме само 50 двубоя и ще завъртим for цикъла само до 50 защото след 50 нямаме играчи, които да
        // участват в двубоите.
        int cnt = players.size() / 2;
        // Ще броим колко двубоя сме направили ако са се провели по-малко от 64 двубоя и нямаме достатъчно състезатели въвеждаме нови такива в турнира.
        int duel_cnt = 0;
        // Програмата сама взема двама състезателя ние избираме само кой е победителя.
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
                cout << "Участниците в този двубой са: " << endl;
                printer_for_players(current_duel);

                cout << "Избери побетдителя от двубоя като въведеш число 1-отговаря за първия 2-отговаря за втория съзтезател: " << endl;
                int num;
                cin >> num;

                Player winner_p = get_P_at_this_index(current_duel, num);
                winners.push_back(winner_p);
                current_duel.pop_front();
                current_duel.pop_front();
                duel_cnt++;
            }
        }

        // За останалите състезатели за които няма опоненти направо ги добавяме към спечелилите.
        while (!players.empty())
        {
            Player p = players.front();
            players.pop_front();
            tournament.pop_player_of_tournament();
            winners.push_back(p);
        }
        // Ако са се провели по-малко от 64 двубоя и нямаме достатъчно състезатели въвеждаме нови такива в турнира.
        if (duel_cnt < 64) {
            int remainder = 64 - duel_cnt;
            cout << "За съжаление няма достатъчно играчи в турнира, за да продължим към 32 финалите" << endl;
            cout << "За да продължим моля добавете " << remainder << " съзтезателя в турнира!" << endl;
            for (int i = 0; i < remainder; i++)
            {
                Player p = addOnePlayer(i);
                winners.push_back(p);
            }

        }
        // Записваме във players всички победители от 64 финалите.
        players = winners;
    }
    // Начало на 32 финали.
    //Проверяваме дали в players имаме 32 или повече играчи, което ще значи, че двубоите ще започнат от 32 финали
    if (players.size() > 32 && players.size() <= 64) {
        int cnt_f_32 = players.size() / 2;
        int d_cnt_32 = 0;
        list<Player> winners_32;
        // Програмата сама взема двама състезателя ние избираме само кой е победителя.
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
                cout << "Участниците в този двубой са: " << endl;
                printer_for_players(current_duel);

                cout << "Избери побетдителя от двубоя като въведеш число 1-отговаря за първия 2-отговаря за втория съзтезател: " << endl;
                int num;
                cin >> num;

                Player winner_p = get_P_at_this_index(current_duel, num);
                winners_32.push_back(winner_p);
                current_duel.pop_front();
                current_duel.pop_front();
                d_cnt_32++;
            }
        }

        // За останалите състезатели за които няма опоненти направо ги добавяме към спечелилите.
        while (!players.empty())
        {
            Player p = players.front();
            players.pop_front();
            tournament.pop_player_of_tournament();
            winners_32.push_back(p);
        }
        // Ако са се провели по-малко от 32 двубоя и нямаме достатъчно състезатели въвеждаме нови такива в турнира.
        if (d_cnt_32 < 32) {
            int remainder = 32 - d_cnt_32;
            cout << "За съжаление няма достатъчно играчи в турнира, за да продължим към 16 финалите" << endl;
            cout << "За да продължим моля добавете " << remainder << " съзтезателя в турнира!" << endl;
            for (int i = 0; i < remainder; i++)
            {
                Player p = addOnePlayer(i);
                winners_32.push_back(p);
            }

        }
        // Слагаме в players всички състезатели, които са победители от 32 финалите така те продължават към 16 финалите.
        players = winners_32;
        tournament.set_n_players(winners_32);
    }
    // Края на 32 финали.

    // Начало на 16 финали.
    if (players.size() > 16 && players.size() <= 32) {
        int cnt_f_16 = players.size() / 2;
        int d_cnt_16 = 0;
        list<Player> winners_16;
        // Програмата сама взема двама състезателя ние избираме само кой е победителя.
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
                cout << "Участниците в този двубой са: " << endl;
                printer_for_players(current_duel);

                cout << "Избери побетдителя от двубоя като въведеш число 1-отговаря за първия 2-отговаря за втория съзтезател: " << endl;
                int num;
                cin >> num;

                Player winner_p = get_P_at_this_index(current_duel, num);
                winners_16.push_back(winner_p);
                current_duel.pop_front();
                current_duel.pop_front();
                d_cnt_16++;
            }
        }

        // За останалите състезатели за които няма опоненти направо ги добяваме към спечелилите.
        while (!players.empty())
        {
            Player p = players.front();
            players.pop_front();
            tournament.pop_player_of_tournament();
            winners_16.push_back(p);
        }
        // Ако са се провели по-малко от 16 двубоя и нямаме достатъчно състезатели въвеждаме нови такива в турнира.
        if (d_cnt_16 < 16) {
            int remainder = 16 - d_cnt_16;
            cout << "За съжаление няма достатъчно играчи в турнира, за да продължим към 16 финалите" << endl;
            cout << "За да продължим моля добавете " << remainder << " съзтезателя в турнира!" << endl;
            for (int i = 0; i < remainder; i++)
            {
                Player p = addOnePlayer(i);
                winners_16.push_back(p);
            }

        }

        // Слагаме във players всички победители от 16 финали и те продължат към осмина финалите.
        players = winners_16;
        tournament.set_n_players(winners_16);
    }

    /* Осмина финали извикваме функцията handmake_duels и така ще съставим всеки един двубой от осмина финалите и ще изберем
    победителите, които ще продължат към четвъртина финалите.
    */
    if (players.size() > 8 && players.size() <= 16) {
        players = handmake_duels(players, tournament);
    }

    /* Четвъртина финали извикваме функцията handmake_duels и така ще съставим всеки един двубой от четвъртина финалите и ще изберем победителите,
    които ще продължат към полуфиналите.
    */
    if (players.size() > 4 && players.size() <= 8) {
        players = handmake_duels(players, tournament);
    }
    // Полуфинали извикваме функцията handmake_duels и така ще съставим всеки един двубой от полуфиналите  и ще изберем победителите, които ще са на финал.
    if (players.size() > 2 && players.size() <= 4) {
        players = handmake_duels(players, tournament);
    }


    // Финал
    if (players.size() == 2) {
        // Принтираме кои са финалистите.
        cout << "Финалистите в турнира са: " << endl;
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

        // Финален двубой.
        current_duel.push_back(first_player);
        current_duel.push_back(second_player);
        cout << endl;
        cout << "Избери побетдителя от двубоя като въведеш число 1-отговаря за първия 2-отговаря за втория съзтезател: " << endl;
        int num;
        cin >> num;

        Player winner_p = get_P_at_this_index(current_duel, num);
        list<Player> winner_in_tournament;
        winner_in_tournament.push_back(winner_p);
        cout << "Победител в турнира е: " << endl;
        // Принтираме победителя.
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

        // Вземаме на първия играч номера в световната ранглиста и го сравняваме с номера на втория играч ако е по-малък връщаме true.
        if (a.get_num_in_world_rankings() < b.get_num_in_world_rankings()) {
            return true;
        }
        // В противен случай връщаме резултат false.
        return false;
    }
};

void players_sorted_world_rankings_num(Tournament tournament) {

    // Правим си лист като вземаме информацията за турнира от структурата Tournament чрез функцията
    //get_data() която връщаше списък с всички играчи.

    list<Player> players_list = tournament.get_data();

    // Правим си обект от класа player_wons_compare!
    player_world_rankings_compare cmp;

    //Сортираме нашия лист във възходящ ред чрез обекта cmp.
    players_list.sort(cmp);

    // Принтираме нашите играчи във възходящ ред според това на кого номера е най-малък в светоната ранглиста.
    printer_for_players(players_list);
}

class alphabeticly_sort {
public:


    bool operator()(Player& a,
        Player& b)
    {

        // Вземаме името на първия играч и го сравняваме с името на втория ако буквата с която започва името на първия е преди буквата с която започва името на
        // втория играч връщаме true.
        if (a.get_first_name() < b.get_first_name()) {
            return true;
        }
        // В противен случай връщаме резултат false.
        return false;
    }
};

// Във функцията target_country_sorted ще сортираме играчите от определена държава по имената им подредени в азбучен ред.
void target_country_sorted(Tournament tournament) {

    string target_country;
    cout << "Моля въведете държава: ";
    cin >> target_country;

    // Лист с всички играчи в турнира
    list<Player> players = tournament.get_data();

    // Лист в който ще съберем всички играчи, които са от определена държава.
    list<Player> target_country_players;

    while (!players.empty())
    {
        Player player_for_compare = players.front();
        players.pop_front();

        // Правим проверка ако на текущия играч държавата е същата като държавата от която искаме да принтираме всички играчи
        //Добавяме го в нашия лист с играчи само от тази държава.
        if (player_for_compare.get_country() == target_country)
            target_country_players.push_back(player_for_compare);
    }
    alphabeticly_sort cmp;
    // Сортираме
    target_country_players.sort(cmp);
    // Принтираме.
    printer_for_players(target_country_players);
}

class t_country_f_places {
public:


    bool operator()(Player& a,
        Player& b)
    {

        // Вземаме на първия играч броя спечелени първи места и сравняваме с тези на втория ако са по-малко
       // връщаме резултат true.
        if (a.get_first_places_cnt() > b.get_first_places_cnt()) {
            return true;
        }
        // В противен случай връщаме резултат false.
        return false;
    }
};
/* Във функцията target_country_first_places_sorter ще сортираме в намаляващ
ред всички играчи от определна държава според това кой има по-малко спечелени първи места(купи)
*/
void target_country_first_places_sorter(Tournament tournament) {
    string target_country;
    cout << "Моля въведете държава: ";
    cin >> target_country;

    // Лист с всички играчи в турнира
    list<Player> players = tournament.get_data();

    // Лист в който ще съберем всички играчи, които са от определена държава.
    list<Player> target_country_players;

    while (!players.empty())
    {
        Player player_for_compare = players.front();
        players.pop_front();

        // Правим проверка ако на текущия играч държавата е същата като държавата от която искаме да принтираме всички играчи
        //Добавяме го в нашия лист с играчи само от тази държава.
        if (player_for_compare.get_country() == target_country)
            target_country_players.push_back(player_for_compare);
    }
    t_country_f_places cmp;
    target_country_players.sort(cmp);
    printer_for_players(target_country_players);

}

// Функция за запазване на всички данни във файл за играчите, които са били в програмта.
void save_data(Tournament tournament) {
    list<Player> players = tournament.get_data();
    ofstream myfile;
    myfile.open("example.txt");
    int players_cnt = players.size();
    myfile << players_cnt << endl;
    // Записваме данните на текущ играч във файла example.txt
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
// Функция за четене на данните, които са били запазени в example.txt така примерно ако сме имали трима играчи преди да спрем прогрмата и сме ги запазили с функцията
// save_data още при стартиране на програмта може да извикаме read_data_from_file и пак в турнира ще са същите трима играчи от предния път.
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

// Меню
void menu() {
    setlocale(LC_ALL, "Bulgarian");
    cout << "                                                   Меню" << endl;
    cout << endl;
    cout << "Въведи едно число, за да избереш команда от менюто: " << endl;
    cout << endl;
    cout << "1: за формиране на нов играч в турнира" << endl;
    cout << endl;
    cout << "2: за формиране на n на брой играчи: " << endl;
    cout << endl;
    cout << "3: за извеждане на всички съзтезатели на екрана" << endl;
    cout << endl;
    cout << "4: за принтиране на играчите с най-малко спечелени купи" << endl;
    cout << endl;
    cout << "5: за принтиране на играчите от определена държава" << endl;
    cout << endl;
    cout << "6: коригиране на данни на съзтезател ако той участва в турнира" << endl;
    cout << endl;
    cout << "7: за съставяне на турнирни двубои по схема до дадени финали" << endl;
    cout << endl;
    cout << "8: за извеждане на съзтезатели сортирани по номер в световната ранглиста" << endl;
    cout << endl;
    cout << "9: за извеждане на съзтезатели от определена държава сортирани по азбучен ред" << endl;
    cout << endl;
    cout << "10: за извеждане на съзтезатели от определена държава сортирани по брой спечелени купи в намаляващ ред";
    cout << endl;
    cout << endl;
    cout << "11: за запазване на данните в програмата във файл" << endl;
    cout << endl;
    cout << "12: за прочитане на запазените данни от предишно стартиране на прогарамта" << endl;
    cout << endl;
}

int main()
{
    // Променлива от тип Tournament в който ще си съхраняваме нашите играчи.
    Tournament tournament;

    setlocale(LC_ALL, "Bulgarian");

    while (true)
    {
        // Меню.
        menu();

        list<Player> players;
        Player player;
        int n;
        string str;

        // Опции в нашето меню.

       // Локална променлива command от тип int на която после ще присвоим информацията от низа str по-долу, за да можем да работим
       // със swtich.
        int command;
        // Прочитаме нашия низ.
        cout << "Въведи число, за да избереш команда от менюто или end за край на програмта! ";
        cin >> str;



        // Проверяваме дали низа не е "end" ако е енд нашата програма приключва.
        if (str == ("end"))
            break;

        // Ако не е end конвертираме го към int и отиваме в кейса, който сме си избрали от менюто и извършваме операциите.
        stringstream converter(str);
        converter >> command;

        cout << endl;
        // От тук ще изберем каква операция искаме да направим дали да формираме един играч или N-на брой такива и т.н.
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
            cout << "Въведи държава: ";

            cin >> str;

            target_country_printer(tournament, str);
            break;

        case 6:
            cout << "Искате да промените данните на определен играч добре " << endl;
            cout << "Tрябва да въведете число, за да намерите играча  чийто данни искате да промените ";
            cout << "Например 1 - за първия играч 2 - за втория и n - за n-тия играч" << endl;
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