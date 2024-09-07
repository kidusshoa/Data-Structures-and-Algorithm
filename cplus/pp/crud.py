maxrow = 10

EmpName = [''] * maxrow
EmpID = [''] * maxrow

def open_file():
    global EmpID, EmpName
    with open("doc.txt", "r") as myfile:
        lines = myfile.readlines()
        x = 0
        for line in lines:
            line = line.strip()
            EmpID[x] = line[:3]
            EmpName[x] = line[4:]
            x += 1

def add_record():
    global EmpID, EmpName
    empno = input("Employee ID: ")
    name = input("Employee Name: ")

    for x in range(maxrow):
        if EmpID[x] == "":
            EmpID[x] = empno
            EmpName[x] = name
            break

def list_record():
    global EmpID, EmpName
    print("Current Record(s)")
    print("===================================")
    counter = 0
    print(" No. |  ID  |     Name    | ")
    print("-------------------------------")
    for x in range(maxrow):
        if EmpID[x] != "":
            counter += 1
            print(f" {counter}    {EmpID[x]}      {EmpName[x]}")
    if counter == 0:
        print("No Record found!")
    print("=====================================")

def search_record(search):
    global EmpID, EmpName
    print("Current Record(s)")
    print("===================================")
    counter = 0
    for x in range(maxrow):
        if EmpID[x] == search:
            counter += 1
            print(f" {counter}    {EmpID[x]}      {EmpName[x]}")
            break
    if counter == 0:
        print("No Record found!")
    print("=====================================")

def update_record(search):
    global EmpName
    counter = 0
    for x in range(maxrow):
        if EmpID[x] == search:
            counter += 1
            name = input("Employee Name: ")
            EmpName[x] = name
            print("Updated Successfully!")
            break
    if counter == 0:
        print("No Record found!")

def delete_record(search):
    global EmpID, EmpName
    counter = 0
    for x in range(maxrow):
        if EmpID[x] == search:
            counter += 1
            EmpID[x] = ""
            EmpName[x] = ""
            print("Deleted Successfully!")
            break
    if counter == 0:
        print("ID Number Does Not Exist!")
    print("================================")

def save_to_file():
    global EmpID, EmpName
    with open("doc.txt", "w") as myfile:
        for x in range(maxrow):
            if EmpID[x] == "":
                break
            else:
                myfile.write(EmpID[x] + "," + EmpName[x] + "\n")

if __name__ == "__main__":
    print("     Menu")
    option = 0
    empID = ""
    open_file()
    print("--------------------------")
    while option != 6:
        print("1-Create Records")
        print("2-Update Records")
        print("3-Delete Records")
        print("4-Search Records")
        print("5-Display all Records")
        print("6-Save and Exit")
        print("===============================")

        option = int(input("Select option >> "))

        if option == 1:
            add_record()
        elif option == 2:
            empID = input("Search by ID >> ")
            update_record(empID)
        elif option == 3:
            empID = input("Delete by ID >> ")
            delete_record(empID)
        elif option == 4:
            empID = input("Search by ID >> ")
            search_record(empID)
        elif option == 5:
            list_record()

    save_to_file()
    print("Exiting and saving records...")
