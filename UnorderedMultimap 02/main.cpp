/*
    You are given a social media dataset containing usernames and the hashtags they follow.
    The dataset is implemented using an unordered_multimap<string, string>, where:

    Key = Username (string)
    Value = Hashtag (string)

    Insert the following data:

    UserA -> #coding
    UserA -> #music
    UserA -> #ai
    UserB -> #travel
    UserB -> #food
    UserC -> #coding
    UserC -> #gaming
    UserC -> #ai
    UserD -> #music
    UserD -> #travel

    Tasks to Implement
    1. Print Users by Hashtag:
        Find and print all unique usernames that follow the hashtag #coding.

    2. Find Intersections:
        Identify and display all users who follow BOTH #coding and #ai.

    3. Find Common Interests:
        Find and print all pairs of users that share at least one common hashtag
        (Avoid duplicate pairs, e.g., if UserA and UserB is printed, UserB and UserA should not be printed).

    4. Remove Duplicate Hashtags:
        Write a function removeDuplicateHashtags that takes a username and the social multimap.
        Then removes any duplicate hashtag entries for that specific user, ensuring each hashtag is unique for them.
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

void removeDuplicateHashtags(string username, unordered_multimap<string,string>& social)
{
    unordered_set<string> uniquehashtags;

    auto range = social.equal_range(username);
    for(auto it = range.first; it != range.second; ++it)
        uniquehashtags.insert(it->second);

    social.erase(username);

    for(auto tag : uniquehashtags)
        social.insert({username,tag});

}

int main()
{
    unordered_multimap<string,string> socialmedia;

    socialmedia.insert({"UserA","#coding"});
    socialmedia.insert({"UserA","#music"});
    socialmedia.insert({"UserA","#music"});
    socialmedia.insert({"UserA","#ai"});
    socialmedia.insert({"UserB","#travel"});
    socialmedia.insert({"UserB","#food"});
    socialmedia.insert({"UserB","#food"});
    socialmedia.insert({"UserC","#coding"});
    socialmedia.insert({"UserC","#gaming"});
    socialmedia.insert({"UserC","#ai"});
    socialmedia.insert({"UserD","#music"});
    socialmedia.insert({"UserD","#travel"});
    socialmedia.insert({"UserD","#travel"});

    unordered_set<string> uniqueusersfollowingtag;
    for(auto user : socialmedia)
        if(user.second == "#coding")
            uniqueusersfollowingtag.insert(user.first);
    cout << "Users following hashtag #coding : " << endl;
    for(auto user : uniqueusersfollowingtag)
        cout << user << endl;

    unordered_set<string> uniqueusers;
    for(auto user : socialmedia)
        uniqueusers.insert(user.first);

    cout << "\nUsers following both #coding and #ai : " << endl;
    for(auto user : uniqueusers)
    {
        bool coding = false;
        bool ai = false;
        auto range = socialmedia.equal_range(user);
        for(auto it = range.first; it != range.second; ++it)
        {
            if(it->second == "#coding") coding = true;
            if(it->second == "#ai") ai = true;
        }
        if(coding && ai)
            cout << user << endl;
    }

    cout << "\nUsernames with atleast one common Hashtags : " << endl;
    for(auto it = uniqueusers.begin(); it != uniqueusers.end(); ++it)
    {
        auto it2 = it;
        ++it2;
        for(; it2 != uniqueusers.end(); ++it2)
        {
            bool common = false;
            auto range1 = socialmedia.equal_range(*it);
            auto range2 = socialmedia.equal_range(*it2);
            for(auto range4 = range1.first; range4 != range1.second; ++range4)
                for(auto range3 = range2.first; range3 != range2.second; ++range3)
                    if(range4->second == range3->second)
                        common = true;
            if(common)
                cout << *it << " and " << *it2 << endl;
        }

    }

    cout << "\nBefore Removing Duplicates : " << endl;
    for(auto user : socialmedia)
        cout << user.first << " - " << user.second << endl;

    removeDuplicateHashtags("UserA",socialmedia);

    cout << "\nAfter Removing Duplicates : " << endl;
    for(auto user : socialmedia)
        cout << user.first << " - " << user.second << endl;

}
