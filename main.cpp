
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include <limits>

#include "Event.cpp"
#include "Attendee.cpp"

using namespace std;

// Funciones

/** The function `readTxt` reads event information from a text file and populates a vector of Event
 * objects with corresponding Attendee objects.
 * 
 * @param listEvent `listEvent` is a vector of `Event` objects. The function `readTxt` reads data from
 * a file named "Info.txt" and populates this vector with events and their corresponding attendees.
 * 
 * @return nothing
 * 
 */
void readTxt(vector<Event>& listEvent);

void menu(vector<Event>& listEvent);

void writeTxt(vector<Event>& listEvent);

void options(vector<Event>& listEvent,int option);

string findMostCommon(vector<Attendee> attendeers);

int main()
{
    vector<Event> listEvent;
    readTxt(listEvent);
    writeTxt(listEvent);
    menu(listEvent);
    cout<<"Fin del programa"<<endl;

    return 0;
}

void readTxt(vector<Event>& listEvent) {

    // Opening the file
    ifstream arch("Info.txt");

    // File verification
    if (!arch.is_open()) {
        cout << "ERROR!!! NO SE ENCONTRO EL ARCHIVO" << endl;
        return;
    }

    string line;

    // Event
    string* type = new string;
    string* location = new string;
    string* topic = new string;
    float* duration = new float;

    string* part = new string;
    vector<string> parts;

    // Attendee
    string* typeAttendee = new string;
    string* name = new string;
    string* occupation = new string;
    string* company = new string;
    int* age = new int;

    while (getline(arch, line)) {

        stringstream ss(line);
        
        while (getline(ss, *part, ';')) {
            parts.push_back(*part);

        }


        *type = string(parts[0]);
        *location = parts[1];
        *topic = parts[2];
        *duration = stof(parts[3]);

        Event event(*type,*location,*topic,*duration);
        
        int iterator = stoi(parts[4]);
        
        for (int i = 0; i < iterator; i++)
        {

            parts.clear();
            getline(arch, line);
            stringstream attendeeLine(line);


            while (getline(attendeeLine, *part, '-')) {
                parts.push_back(*part);

            }

            *typeAttendee = parts[0];
            *name = parts[1];
            *occupation = parts[2];
            *company = parts[3];
            *age = stoi(parts[4]);
            
            Attendee attendee(*typeAttendee,*name,*occupation,*company,*age);
            event.addAttendee(attendee);

            parts.clear();
        }

        listEvent.push_back(event);
        

        
    }
    //Delete
    delete type ;
    delete location;
    delete topic;
    delete duration;

    delete part;

    // Attendee
    delete typeAttendee;
    delete name;
    delete occupation;
    delete company;
    delete age;

    arch.close();

    
};
//This function is responsible for writing in the txt file all the data that the list of events has 
//and also the attendees of these events

void writeTxt(vector<Event>& listEvent){

    ofstream file;

    file.open("Info.txt",ios::out); //open the file

    if (file.fail())
    {
        cout<< "Error al abrir el archivo"<<endl;
        exit(1);
    }
    //loops through the events and writes them to the txt
    for (size_t i = 0; i < listEvent.size(); i++)
    {
        
        file<<listEvent[i].getType()<<";"<<listEvent[i].geLocation()<<";"<<listEvent[i].getTopic()<<";"<<listEvent[i].getDuration()<<";"<<listEvent[i].getAttendees().size()<<endl;
        
        vector<Attendee> attendeers = listEvent[i].getAttendees();

        //write the event attendees in the txt
        for (size_t j = 0; j < attendeers.size(); j++)
        {
            
            file<<attendeers[j].getTypeAttendee()<<"-"<<attendeers[j].getName()<<"-"<<attendeers[j].getOccupation()<<"-"<<attendeers[j].getCompany()<<"-"<<attendeers[j].getAge()<<endl;
        }

    }

};

//Find the most common ocupattion
string findMostCommon(vector<Attendee> attendeers){

    vector<string> ocupattion;
    vector<int> intOcupattion;

    for (int j = 0; j < attendeers.size(); j++)
        {
            bool foundOcuptaion = false;
            //cout<<"Tipo: "<<attendeers[j].getTypeAttendee()<<"/Nombre: "<<attendeers[j].getName()<<"/Ocupacion: "<<attendeers[j].getOccupation()<<"/Compania: "<<attendeers[j].getCompany()<<"/Edad: "<<attendeers[j].getAge()<<endl;
            for (int k = 0; k < ocupattion.size(); k++)
            {
                if (ocupattion[k] == attendeers[j].getOccupation())
                {
                    foundOcuptaion = true;
                    intOcupattion[j]=+1;
                }
                
            }

            if (!foundOcuptaion)
            {
                ocupattion.push_back(attendeers[j].getCompany());
                intOcupattion.push_back(1);
            }     
            
        }

    int maxAux = 0;
    int indAux = 0;
    vector<int> maxRep;
    vector<string> maxRepString;
    

    if (ocupattion.size() > 3) {

            for (int i = 0; i < 3; i++) {

                for (int j = 0; j < intOcupattion.size(); j++) {

                    if (intOcupattion[j] > maxAux && maxAux == 0) {
                        maxAux = intOcupattion[j];
                        indAux = j;

                    } else if (intOcupattion[j] > maxAux) {
                        maxAux = intOcupattion[j];
                        indAux = j;
                        
                    }

                }

                maxRep.push_back(maxAux);
                maxRepString.push_back(ocupattion[indAux]);
                maxAux = 0;
                intOcupattion[indAux] = 0;
                ocupattion[indAux] = "";
                
        }

        for (int i = 0; i < maxRepString.size(); i++) {
            cout << maxRepString[i]<< endl;
        }
    } else {
        for (int i = 0; i < ocupattion.size(); i++)
        {
            cout << ocupattion[i] << endl;
        }
        
    }
    

    
    

};

//This function is responsible for managing the procedures that must be carried out given the selection of one of the menu options.
void options(vector<Event>& listEvent,int option){

    switch (option)
    {
    case 1: {

    
        cout<<"Ingrese los datos del evento:"<<endl;
        cout<<"Tipo:"<<endl;

        string type;

        cin>>type;

        cout<<"Ubicacion"<<endl;

        string location;

        cin>>location;

        cout<<"Tema"<<endl;
        string topic;
        cin>>topic;

        cout<<"Duracion"<<endl;
        float duration;
        cin>>duration;

        Event event(type,location,topic,duration);

        cout<<"Ingrese la cantidad de asistentes que asistiran al evento:"<<endl;
        //a sweep of the entered data is carried out due to an error that occurred
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int quantityAttendees;
        cin>>quantityAttendees;
        //iterates by the number of attendees who want to register for the event
        for (size_t i = 0; i < quantityAttendees; i++)
        {
            
            cout<<"Ingrese los datos del asistente:"<<endl;
            cout<<"Nombre:"<<endl;

            string name;

            cin>>name;

            cout<<"Tipo de asistente"<<endl;

            string typeAttendee;

            cin>>typeAttendee;

            cout<<"Ocupacion"<<endl;
            string occupation;
            cin>>occupation;

            cout<<"Compañia"<<endl;
            string company;
            cin>>company;

            cout<<"Edad"<<endl;
            int age;
            cin>>age;

            Attendee attendee(typeAttendee,name,occupation,company,age);
            event.addAttendee(attendee);

        }
        //The event is added with all its data to the list and all the data in the list is written to the txt.
        listEvent.push_back(event);
        writeTxt(listEvent);

        break;
    }
    case 2:{

        cout<<"En que evento desea registrar nuevos asistentes?"<<endl;
        //print the events whit his information.
        for (size_t i = 0; i < listEvent.size(); i++)
    {
        cout<<i<<") "<<listEvent[i].getType()<<";"<<listEvent[i].geLocation()<<";"<<listEvent[i].getTopic()<<";"<<listEvent[i].getDuration()<<";"<<listEvent[i].getAttendees().size()<<endl;

    }
        int option;
        cin>>option;

        cout<<listEvent.size()-1<<"---"<<option<<endl;
    //error control in case of entering invalid data
    while (option>listEvent.size()-1 || option<0)
    {
        cout<<"Error, ingrese una opcion valida"<<endl;
        for (size_t i = 0; i < listEvent.size(); i++)
    {
        cout<<i<<") "<<listEvent[i].getType()<<";"<<listEvent[i].geLocation()<<";"<<listEvent[i].getTopic()<<";"<<listEvent[i].getDuration()<<";"<<listEvent[i].getAttendees().size()<<endl;

    }
        cin>>option;
    }
    
        cout<<"Ingrese la cantidad de asistentes que desea registrar:"<<endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int quantityAttendees;
        cin>>quantityAttendees;
        //iterates by the number of attendees who want to register for the event
        for (size_t i = 0; i < quantityAttendees; i++)
        {
            
            cout<<"Ingrese los datos del asistente:"<<endl;
            cout<<"Nombre:"<<endl;

            string name;

            cin>>name;

            cout<<"Tipo de asistente"<<endl;

            string typeAttendee;

            cin>>typeAttendee;

            cout<<"Ocupacion"<<endl;
            string occupation;
            cin>>occupation;

            cout<<"Compañia"<<endl;
            string company;
            cin>>company;

            cout<<"Edad"<<endl;
            int age;
            cin>>age;

            //Create and add the new attendee
            Attendee attendee(typeAttendee,name,occupation,company,age);
            listEvent[option].addAttendee(attendee);

        }
        //The data from the event list where the new registered attendees are already registered is written in the txt
        writeTxt(listEvent);

        break;
    }
    
    case 3:{

        cout<<"Seleccione el evento del cual quiere ver la lista de asistentes: "  <<endl;
        cout<< " " <<endl;

        for (size_t i = 0; i < listEvent.size(); i++)
    {
        cout<<i<<") Tipo: "<<listEvent[i].getType()<<"/Ubicacion: "<<listEvent[i].geLocation()<<"/Tema: "<<listEvent[i].getTopic()<<"/Duracion: "<<listEvent[i].getDuration()<<"hrs"<<endl;

    }
        int option;
        cin>>option;

    //error control in case of entering invalid data
    while (option>listEvent.size()-1 || option<0)
    {
        cout<<"Error, ingrese una opcion valida"<<endl;
        for (size_t i = 0; i < listEvent.size(); i++)
        {
        cout<<i<<") Tipo: "<<listEvent[i].getType()<<"/Ubicacion: "<<listEvent[i].geLocation()<<"/Tema: "<<listEvent[i].getTopic()<<"/Duracion: "<<listEvent[i].getDuration()<<"hrs"<<endl;

        }
        cin>>option;
    }

        vector<Attendee> attendeers = listEvent[option].getAttendees();
        //iterates by the number of attendees who go to the event
        for (size_t j = 0; j < listEvent[option].getAttendees().size(); j++)
        {
            
            cout<<"Tipo: "<<attendeers[j].getTypeAttendee()<<"/Nombre: "<<attendeers[j].getName()<<"/Ocupacion: "<<attendeers[j].getOccupation()<<"/Compania: "<<attendeers[j].getCompany()<<"/Edad: "<<attendeers[j].getAge()<<endl;
            
        }

        break;
        
    }

    case 4: {

        cout<<"---Informe sobre eventos y asistentes registrados---"<<endl;
        
        cout<<"Eventos registrados:"<<endl;
        
        int averageAttendees = 0;

        //print the events whit his information.
        for (size_t i = 0; i < listEvent.size(); i++) {
            cout<<i+1<<". Tipo: "<<listEvent[i].getType()<<"/Ubicacion: "<<listEvent[i].geLocation()<<"/Tema: "<<listEvent[i].getTopic()<<"/Duracion: "<<listEvent[i].getDuration()<<"hrs"<<endl;

        }
        
        cout<<"---Asistentes registrados para cada evento: ---"<<endl;
        
        //print the attendeers whit his information.

        for (size_t i = 0; i < listEvent.size(); i++) {
            cout<<i+1<<") Tipo: "<<listEvent[i].getType()<<"/Ubicacion: "<<listEvent[i].geLocation()<<"/Tema: "<<listEvent[i].getTopic()<<endl;

        vector<Attendee> attendeers = listEvent[i].getAttendees();

        cout<< " " <<endl;
        cout<<"----- Asistentes -------"<<endl;
        cout<< " " <<endl;
        
        int averageAgeAttendeers = 0;

        for (size_t j = 0; j < attendeers.size(); j++)
        {
            
            cout<<"Tipo: "<<attendeers[j].getTypeAttendee()<<"/Nombre: "<<attendeers[j].getName()<<"/Ocupacion: "<<attendeers[j].getOccupation()<<"/Compania: "<<attendeers[j].getCompany()<<"/Edad: "<<attendeers[j].getAge()<<endl;
            averageAgeAttendeers += attendeers[j].getAge();
            
        }
        averageAttendees += attendeers.size();

        cout<< " " <<endl;
        cout<<"--- Numero total de asistentes al evento: "<<attendeers.size()<<" ---"<<endl;
        cout<< " " <<endl;
        cout<<"--- La edad promedio de los asistentes es de: "<<averageAgeAttendeers/attendeers.size()<<" anos ---"<<endl;
        cout<< " " <<endl;
        cout<<"--- Ocupaciones mas comunes"<<endl;
        cout<< " " <<endl;
        findMostCommon(attendeers);
        cout<< " " <<endl;
    }
    
    cout<<"--- El promedio de asistentes por evento es de : "<<averageAttendees/listEvent.size()<<" ---"<<endl;

    }

    default:
        break;
    }

};

void menu(vector<Event>& listEvent) {
    
    cout<< " " <<endl;
    cout<< "--- Seleccione la accion que desea realizar ---" <<endl;
    cout<< " " <<endl;
    cout<< "1) Creacion de un nuevo evento"<<endl;
    cout<< "2) Registrar asistentes a un evento"<<endl;
    cout<< "3) Ver la lista de asistentes"<<endl;   
    cout<< "4) Mostrar un informe"<<endl;

    int option;
    cout<< " " <<endl;
    cout<< "Ingrese la opcion: " <<endl;
    cout<< " " <<endl;
    cin>>option;
    //error control in case of entering invalid data
    while (option!=1 && option!=2 && option!=3 && option!=4)
    {
        cout<<"Es distinto de 0"<<endl;
        cout<< "--- Error, Seleccione una opcion valida ---"<<endl;
        cout<< " " <<endl;
        cout<< "1) Creacion de un nuevo evento"<<endl;
        cout<< "2) Registrar asistentes a un evento"<<endl;
        cout<< "3) Ver la lista de asistentes"<<endl;
        cout<< "4) Mostrar un informe"<<endl;
        cout<< " " <<endl;
        cout<< "Ingrese la opcion: " <<endl;
        cout<< " " <<endl;
        cin>>option;
    }
    
    options(listEvent,option);

    cout<<"Desea realizar otra accion?"<<endl;
    cout<<"1) Para si"<<endl;
    cout<<"2) No"<<endl;
    cout<< " " <<endl;
    cout<< "Ingrese la opcion: " <<endl;
    cout<< " " <<endl;
    cin>>option;
    
    if (option == 1)
    {
        menu(listEvent);
    }
    
}