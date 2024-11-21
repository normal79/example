














#!/bin/bash


ADDRESS_BOOK="address_book.txt"


add_entry() {
    echo "Enter Name:"
    read name
    echo "Enter Email:"
    read email
    echo "Enter Mobile Number:"
    read mobile
    echo "Enter Address:"
    read address
    echo "Enter Other Important Fields (separated by commas):"
    read other_fields

    echo "$name,$email,$mobile,$address,$other_fields" >> "$ADDRESS_BOOK"
    echo "Entry added successfully!"
}

display_entries() {
    if [ ! -s "$ADDRESS_BOOK" ]; then
        echo "Address book is empty."
    else
        cat "$ADDRESS_BOOK"
    fi
}

search_entries() {
    echo "Enter the name to search:"
    read name
    grep -i "$name" "$ADDRESS_BOOK"
}


update_entry() {
    echo "Enter the name of the entry to update:"
    read name
    entry=$(grep -i "$name" "$ADDRESS_BOOK")
    if [ -z "$entry" ]; then
        echo "No entry found with that name."
        return
    fi

    echo "Current entry: $entry"
    echo "Enter new Email:"
    read email
    echo "Enter new Mobile Number:"
    read mobile
    echo "Enter new Address:"
    read address
    echo "Enter new Other Important Fields (separated by commas):"
    read other_fields

    sed -i.bak "/$name/d" "$ADDRESS_BOOK"
    echo "$name,$email,$mobile,$address,$other_fields" >> "$ADDRESS_BOOK"
    echo "Entry updated successfully!"
}


delete_entry() {
    echo "Enter the name of the entry to delete:"
    read name
    grep -i "$name" "$ADDRESS_BOOK"
    if [ $? -eq 0 ]; then
        sed -i.bak "/$name/d" "$ADDRESS_BOOK"
        echo "Entry deleted successfully!"
    else
        echo "No entry found with that name."
    fi
}


while true; do
    echo "Address Book Menu"
    echo "1. Add Entry"
    echo "2. Display All Entries"
    echo "3. Search Entry"
    echo "4. Update Entry"
    echo "5. Delete Entry"
    echo "6. Exit"
    echo "Enter your choice:"
    read choice

    case $choice in
        1) add_entry ;;
        2) display_entries ;;
        3) search_entries ;;
        4) update_entry ;;
        5) delete_entry ;;
        6) exit ;;
        *) echo "Invalid choice. Please enter a number between 1 and 6." ;;
    esac
done 
