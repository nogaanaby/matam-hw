

gcc BinaryTree.c BinaryTree.h Client.c Utils.c Supplier.c Car.c test.c Client.h Utils.h Supplier.h Car.h test.h main.c -o main

gcc Client.c Utils.c Supplier.c Car.c test.c Client.h Utils.h Supplier.h Car.h test.h main.c -ansi -Wall -pedantic -errors -lm -o main


todo:
q1 - graphs
q2:
    - general binarySearchTree
        -createTree
        -addNewNode
        -removeNode
        -findNode
        -averageKey
        -treeToArray
        -printTree
        -freeTree
    car:
        -createCarTree
        -addNewCar
        *carNumberWithGivenCapacity
        -deleteCar
        -deleteAllCars
    client:
        -createClientTree
        -addNewClient
        *clientNumberWithGivenCarYear
        *findClient
        -printClientCarsForGivenRentDate
        -deleteClient
        -deleteAllClients
    supplier:
        -createSupplierTree
        -addNewSupplier
        *averageOfSupplierMoney
        *threeGreatestSuppliers
        *printSuppliers
        -deleteSupplier
        -deleteAllSuppliers


Noga:
    - general binarySearchTree
        -createTree
        -addNewNode
        -removeNode
        -findNode
        -averageKey
        -treeToArray
        -printTree
        -freeTree
    
    client:
        -createClientTree
        -addNewClient
        *clientNumberWithGivenCarYear
        *findClient
        -printClientCarsForGivenRentDate
        -deleteClient
        -deleteAllClients

    supplier:
        -createSupplierTree
        -addNewSupplier
        *averageOfSupplierMoney
        *threeGreatestSuppliers
        *printSuppliers
        -deleteSupplier
        -deleteAllSuppliers        

Shahar:
    - q1 - graphs 
    car:
        -createCarTree
        -addNewCar
        *carNumberWithGivenCapacity
        -deleteCar
        -deleteAllCars
