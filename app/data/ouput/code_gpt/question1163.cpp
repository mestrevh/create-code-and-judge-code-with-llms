/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> pokemons = {
        "Bulbasaur", "Ivysaur", "Venusaur", "Charmander", "Charmeleon", 
        "Charizard", "Squirtle", "Wartortle", "Blastoise", "Caterpie", 
        "Metapod", "Butterfree", "Weedle", "Kakuna", "Beedrill", 
        "Pidgey", "Pidgeotto", "Pidgeot", "Rattata", "Raticate", 
        "Spearow", "Fearow", "Ekans", "Arbok", "Pikachu", 
        "Raichu", "Sandshrew", "Sandslash", "Nidoran♀", "Nidorina", 
        "Nidoqueen", "Nidoran♂", "Nidorino", "Nidoking", "Clefairy", 
        "Clefable", "Vulpix", "Ninetales", "Jigglypuff", "Wigglytuff", 
        "Zubat", "Golbat", "Oddish", "Gloom", "Vileplume", 
        "Paras", "Parasect", "Venonat", "Venomoth", "Diglett", 
        "Dugtrio", "Meowth", "Persian", "Psyduck", "Golduck", 
        "Poliwag", "Poliwhirl", "Poliwrath", "Abra", "Kadabra", 
        "Alakazam", "Machop", "Machoke", "Machamp", "Bellsprout", 
        "Weepinbell", "Victreebel", "Tentacool", "Tentacruel", "Geodude", 
        "Graveler", "Golem", "Ponyta", "Rapidash", "Slowpoke", 
        "Slowbro", "Magnemite", "Magneton", "Farfetch'd", "Doduo", 
        "Dodrio", "Seel", "Dewgong", "Grimer", "Muk", 
        "Shellder", "Cloyster", "Gastly", "Haunter", "Gengar", 
        "Onix", "Drowzee", "Hypno", "Krabby", "Kingler", 
        "Voltorb", "Electrode", "Exeggcute", "Exeggutor", "Cubone", 
        "Marowak", "Hitmonlee", "Hitmonchan", "Lickitung", "Koffing", 
        "Weezing", "Rhyhorn", "Rhydon", "Chansey", "Tangela", 
        "Kangaskhan", "Horsea", "Seadra", "Goldeen", "Seaking", 
        "Staryu", "Starmie", "Mr. Mime", "Scyther", "Jynx", 
        "Electabuzz", "Magmar", "Pinsir", "Tauros", "Magikarp", 
        "Gyarados", "Lapras", "Ditto", "Eevee", "Vaporeon", 
        "Jolteon", "Flareon", "Porygon", "Omanyte", "Omastar", 
        "Kabuto", "Kabutops", "Aerodactyl", "Snorlax", "Articuno", 
        "Zapdos", "Moltres", "Dratini", "Dragonair", "Dragonite", 
        "Mewtwo", "Mew"
    };
    
    int p;
    cin >> p;

    if (p < 1 || p > 151) {
        cout << "Pokémon inválido no momento" << endl;
    } else {
        cout << pokemons[p - 1] << endl;
    }

    return 0;
}
