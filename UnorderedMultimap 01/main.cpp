#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    unordered_multimap<string,string> registry;

    registry.insert({"Alice","Math"});
    registry.insert({"Bob","Physics"});
    registry.insert({"Alice","Chemistry"});
    registry.insert({"Charlie","Biology"});
    registry.insert({"Bob","Math"});

    for(auto it : registry)
        cout << it.first << " - " << it.second << endl;

    cout << "\nBob is taking : " << registry.count("Bob") << " subjects" << endl;

    cout << "\nAlice is taking : ";
    auto alicerange = registry.equal_range("Alice");
    for( auto it = alicerange.first; it!=alicerange.second; ++it)
        cout << it->second << " ";

    cout << "\n\n";
    registry.erase("Charlie");
    for(auto it : registry)
        cout << it.first << " - " << it.second << endl;

    if(registry.count("David")==0)
        cout << "\nDavid Not Found\n";
    else
        cout << "\nDavid Found\n";

    bool alreadyexists = false;

    auto bobrange = registry.equal_range("Bob");
    for(auto it = bobrange.first; it!=bobrange.second; ++it)
        if(it->second == "Physics")
        {
            alreadyexists = true;
            break;
        }
    if(alreadyexists == false)
        registry.insert({"Bob","Physics"});
    else
        cout << "\nPhysics already exists for Bob\n";

    unordered_set<string> uniquestudents;
    for(auto it : registry)
        uniquestudents.insert(it.first);
    cout << "\nUnique Students : ";
    for(auto it : uniquestudents)
        cout << it << " ";

        cout << "\n\nMaximum Subjects Taking Students : ";
        int maximum = 0;
        for (auto it : uniquestudents)
            if(registry.count(it)>maximum)
            maximum = registry.count(it);
        for(auto it : uniquestudents)
            if(registry.count(it) == maximum)
            cout << it << " ";

        auto alicerange2 = registry.equal_range("Alice");
    for(auto it = alicerange2.first; it!=alicerange2.second; ++it)
        if(it->second == "Chemistry")
        {
            registry.erase(it);
            cout << "\n\nChemistry Removed from Alice\n";
        }

        auto alicerange3 = registry.equal_range("Alice");
       for(auto it = alicerange3.first; it!=alicerange3.second; ++it)
        cout << it->second << " ";
}
