#include<iostream>
#include<ctime>
#include<string.h>
using namespace std;

struct movies
{
    char movie[65], director[65], genre[65];
    float rating, price;
};

void inscription(movies pat)
{
    cout << "Movie title: " << pat.movie
        << "\nDirector: " << pat.director
        << "\nGenre: " << pat.genre
        << "\nRating: " << pat.rating
        << "\nPrice: " << pat.price << "\n" << endl;
}

bool searchbytitle(movies film[], char user[], int lenght)
{
    bool button = 0;
    for (int i = 0; i < lenght; i++)
    {
        if (strstr(film[i].movie, user) != NULL)
        {
            cout << film[i].movie << " ";
            button = true;
            break;
        }
        else 
        {
            button = false;
        }
    }
    return button;
}

void searchbygenre(movies film, char user[])
{
    if (strstr(film.genre, user) != NULL)
        cout << film.movie << " ";
}

void searchbydirector(movies film, char user[])
{
    if (strstr(film.director, user) != NULL)
        cout << film.movie << " ";
}

int main()
{
    cout << "\tMOVIE STORE \nWhich criteria to use to find the movie?" << endl;
    const int length = 10;
    int button = 0;

    movies moviesearch[length]
    {
        { "Kill Bill", "Quentin Tarantino", "Action", 7.7, 150 },
        { "Fear and Loathing in Las Vegas", "Terry Gilliam", "Adventure", 7.6, 150 },
        { "Interstellar", "Christopher Nolan","Sci-Fi", 8.6, 170 },
        { "Tom and Jerry", "Joseph Barbera and William Hanna", "Cartoon TV Series", 8.7, 170 },
        { "Coraline", "Henry Selick", "Animation", 7.8, 160 },
        { "Spirited Away", "Hayao Miyazaki", "Anime", 8.5, 170 },
        { "Alien", "Ridley Scott", "Horror", 8.1, 160 },
        { "Breaking Bad", "Vince Gilligan", "Crime", 7.0, 140 }
    };
    do
    {
        cout << "1 - By title" << endl
        << "2 - By genre" << endl
        << "3 - By directior" << endl
        << "4 - Show our movies" << endl
        << "0 - Exit" << endl;
        cin >> button;
        cout << endl;
   
        switch (button)
        {
        case 1:

            char user1[65];
            cout << "Enter title: ";
            cin >> user1;
            if (searchbytitle(moviesearch, user1, length) == true)
            {
                cout << "(the movie is found)\n" << endl;
            }
            else
                cout << "(the movie isn't found) :(";
            break;

        case 2:
            char user2[65];
            cout << "Enter genre: ";
            cin >> user2;
            for (int i = 0; i < length; i++)
            {
                searchbygenre(moviesearch[i], user2);
                cout << endl;
            }
            break;
        case 3:
            char user3[65];
            cout << "Enter director's name: ";
            cin >> user3;
            for (int i = 0; i < length; i++)
            {
                searchbydirector(moviesearch[i], user3);
            }
            cout << endl;
            break;
        case 4:

            for (int i = 0; i < length; i++)
                inscription(moviesearch[i]);
            break;
        case 0:
            cout << "Bye!" << endl;
            break;
        default:
            cout << "?" << endl;
            break;
        }
        } while (button == 4);
    cout << endl; cout << endl;

    system("pause");
    return 0;
}