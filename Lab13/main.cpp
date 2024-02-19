#include <iostream>
#include <fstream>
#include "CampsiteRecord.h"
#include "Campsite.h"
#include "CampsiteDB.h"
using namespace std;
int main()
{

    CampsiteRecord site_rec1;   
    cout << "Empty record: " << site_rec1 << "\n";

    CampsiteRecord site_rec2{42, "Lakefront Cabin", true, 300.00};
    cout << "Non-empty record: " << site_rec2 << "\n";

    ifstream fin{"sites.txt"};
    from_ascii_file(fin, site_rec1);
    fin.close();
    cout << "First site from file: " << site_rec1 << "\n";
    Campsite site1 {3, "Riverfront Condo", true, 450.00};
    cout << site1 << '\n';


    CampsiteDB db{"campsites.db"};
    cout << "File currently contains " << db.get_record_count() << " records.\n\n";
    fin.open("sites.txt");
    while(fin.good()){
        Campsite site;
        if(site.from_ascii_file(fin)){
            cout << "Adding " << site << "\n";
            db.write_next_sequential(site);
        }
    }
    cout << "\n\n";
    fin.close();    


    cout << "Read index is "  << db.get_current_index() << "\n";
    cout << "Write index is " << db.get_current_index(true) << "\n";
    cout << "File now contains " << db.get_record_count() << " records.\n\n";
    db.list_records();
    cout << "\n";

    Campsite result;
    result = db.get_at_index(9); 
    cout << result << "\n";
    result = db.get_at_index(3); 
    cout << result << "\n";
    result = db.get_at_index(6); 
    cout << result << "\n\n";

    db.write_at_index(8, Campsite{18, "Pavillion", true, 200.00});
    db.write_at_index(2, Campsite{12, "Treehouse", false, 250.00});

    result = db.get_at_index(8); 
    cout << result << "\n";
    result = db.get_at_index(2); 
    cout << result << "\n";

    return 0;
}