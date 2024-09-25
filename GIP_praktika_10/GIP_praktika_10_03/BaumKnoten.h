#pragma once
class BaumKnoten {
private:
    int data;
    BaumKnoten* links;
    BaumKnoten* rechts;

public:
    BaumKnoten(int data, BaumKnoten* links = nullptr, BaumKnoten* rechts = nullptr);
    ~BaumKnoten();
    // Getter and Setter for data
    int get_data() ;
    void set_data(int value);

    // Getter and Setter for links
    BaumKnoten* get_links() ;
    void set_links(BaumKnoten* node);

    // Getter and Setter for rechts
    BaumKnoten* get_rechts() ;
    void set_rechts(BaumKnoten* node);

    // Method to print the tree
    void ausgeben(unsigned int tiefe) ;
};

