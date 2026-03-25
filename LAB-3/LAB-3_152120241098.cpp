#include <iostream>
using namespace std;

typedef struct Song{
    string title;
    string artist;
    int rating[3] = {0,0,0};
    Song*Next;
    Song*Prev;
};Song* head = NULL; 
Song* current = NULL;


void add ( string a){
  Song* newSong = new Song();
  newSong->title = a;
  newSong->Next = NULL;
  newSong->Prev = NULL;
  
  if(head ==NULL) head=newSong, current= newSong;
  else {
        Song* temp = head;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newSong;
        newSong->Prev = temp;
    }
  

}
void nextSong(string a){
    if(current == NULL){
        cout<<"There is no next song.\n";
        return;
    }
    if(current->Next == NULL){
        cout<<"There is no next song.\n";
        return;
    }
    current = current->Next;
}
void prevSong(string a){
    if(current == NULL){
        cout<<"There is no previous song.\n";
        return;
    }
    if(current->Prev == NULL){
        cout<<"There is no previous song.\n";
        return;
    }
    current = current->Prev;
}
void removecurrent (string a){
    if(head==NULL){
    cout<<"There is no song to remove.\n";
    return;
    } 
    if(head->Next == NULL){
        delete head;
        head= NULL;
        return;
    }
    else{
        Song* temp = head;
        head= head->Next;
        head->Prev = NULL;
        delete temp;
    }

}

void Display(string a){
    Song* newSong = head;
    while(newSong != NULL){
        if(newSong == current){
            cout<< "->";
        }
        cout<< newSong->title <<" Ratings: ";
        for (int i = 0; i < 3; i++) {
            cout << newSong->rating[i] << " ";
        }

        newSong = newSong->Next;

    }
}
int main(){
    while(true){
        string a;
        cout<<"Enter the command: (add/remove/next/prev/display/exit) ";
        cin>>a;
        if(a=="add"){
            string b;
            cout<<"Enter the song title: ";
            cin>>b;
            add(b); 
        }
        if(a=="remove"){
            removecurrent(a);
        }
        if(a=="prev"){
            prevSong(a);
        }
        if(a=="next"){
            nextSong(a);
        }
        if(a=="display"){
            Display(a);
        }
        if(a=="exit"){
            cout<<"You have exited from the playlist\n";
            return false;
        }
      
    }



    return 0;
}
