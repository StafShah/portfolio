-- TABLES
-- Table to store product information
CREATE TABLE Inventory (
    ProductID INT PRIMARY KEY,
    CategoryID INT,
    BrandID INT,
    SupplierID INT,
    SKU VARCHAR(50),
    Name VARCHAR(255),
    QuantityInStock INT,
    QuantitySold INT,
    Price DECIMAL(10, 2),
    Discount DECIMAL(5, 2)
);

-- Table to store user information
CREATE TABLE Users (
    UserID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Email VARCHAR(255),
    Password VARCHAR(255),
    MobileNumber VARCHAR(20),
    RegistrationTimestamp DATETIME,
    LastLoginTimestamp DATETIME
);

-- Table to store vendor (supplier) information
CREATE TABLE Vendors (
    SupplierID INT PRIMARY KEY,
    Name VARCHAR(255),
    TotalPurchasedStockValue DECIMAL(15, 2),
    UnitPrice INT
);

-- Table to store transaction information
CREATE TABLE Transactions (
    TransactionID INT PRIMARY KEY,
    UserID INT,
    Subtotal DECIMAL(10, 2),
    Tax DECIMAL(10, 2),
    ShippingFee DECIMAL(10, 2),
    ShippingType VARCHAR(50),
    GrandTotal DECIMAL(15, 2),
    PromoCode VARCHAR(50),
    Discount DECIMAL(5, 2),
    OrderStatus VARCHAR(50),
    CreationTimestamp DATETIME,
    UpdateTimestamp DATETIME
);

-- Table to store item information for transactions
CREATE TABLE TransactionItems (
    TransItemID INT PRIMARY KEY,
    TransactionID INT,
    ProductID INT,
    PurchasePrice DECIMAL(10, 2),
    Discount DECIMAL(5, 2),
    Quantity INT,
    CreationTimestamp DATETIME,
    UpdateTimestamp DATETIME,
    Memo TEXT
);

-- Table to store address information
CREATE TABLE Addresses (
    AddressID INT PRIMARY KEY,
    UserID INT,
    UserName VARCHAR(100),
    PhoneNumber VARCHAR(20),
    EmailAddress VARCHAR(255),
    AddressInfo TEXT,
    CreationTimestamp DATETIME,
    UpdateTimestamp DATETIME
);

-- Table to store category information
CREATE TABLE Category (
    CategoryID INT PRIMARY KEY,
    Category VARCHAR(255),
    Description TEXT
);

-- Table to store brand information
CREATE TABLE Brand (
    BrandID INT PRIMARY KEY,
    BrandName VARCHAR(50),
    BrandDesc TEXT
);

-- Table to track activity on the inventory log
CREATE TABLE AuditTrail_Inventory (
    AuditID INT PRIMARY KEY AUTO_INCREMENT,
    ActionType VARCHAR(10) NOT NULL,
    UserID VARCHAR(50) NOT NULL,
    Timestamp DATETIME NOT NULL,
    OldValue TEXT,
    NewValue TEXT
);

-- FOREIGN KEYS
ALTER TABLE Inventory
ADD FOREIGN KEY(CategoryID)    
REFERENCES Category(CategoryID)
ON DELETE NO ACTION;

ALTER TABLE Inventory
ADD FOREIGN KEY(BrandID) 
REFERENCES Brand(BrandID)
ON DELETE NO ACTION;

ALTER TABLE Inventory
ADD FOREIGN KEY(SupplierID)    
REFERENCES Vendors(SupplierID)
ON DELETE NO ACTION;

ALTER TABLE Transactions
ADD FOREIGN KEY(UserID)    
REFERENCES Users(UserID)
ON DELETE NO ACTION;

ALTER TABLE Addresses
ADD FOREIGN KEY(AddressID)    
REFERENCES Users(UserID)
ON DELETE NO ACTION;

ALTER TABLE TransactionItems
ADD FOREIGN KEY(TransactionID)
REFERENCES Transactions(TransactionID)
ON DELETE NO ACTION;

ALTER TABLE TransactionItems
ADD FOREIGN KEY(ProductID)
REFERENCES Inventory(ProductID)
ON DELETE NO ACTION;

-- INVENTORY QUERIES
-- Query to retrieve all inventory
SELECT * FROM Inventory;

-- Query to retrieve inventory item by productID
SELECT * FROM Inventory WHERE ProductID = [ProductID];

-- Query to retrieve inventory items by category
SELECT * FROM Inventory WHERE CategoryID = [CategoryID];

-- Query to retrieve inventory items by brand
SELECT * FROM Inventory WHERE BrandID = [BrandID];

-- Query to retrieve inventory items with quantity in stock below a certain number
SELECT * FROM Inventory WHERE QuantityInStock < [Threshold];

-- Query to retrieve items on discount
SELECT * FROM Inventory WHERE Discount > 0;

-- Query to retrieve items sorted by price
SELECT * FROM Inventory ORDER BY Price;

-- Query to retrieve the total stock value of each item
SELECT ProductID, Name, Price * QuantityInStock AS TotalStockValue
FROM Inventory;

-- Query to retrieve items and their respective brands
SELECT Inventory.*, Brand.BrandName
FROM Inventory
LEFT JOIN Brand ON Inventory.BrandID = Brand.BrandID;

-- Query to retrieve stock information for each item
SELECT ProductID, Name, QuantityInStock, QuantitySold
FROM Inventory;

-- USER QUERIES
-- Query to retrive all users
SELECT * FROM Users;

-- Query to retrieve user by userID
SELECT * FROM Users WHERE UserID = [UserID];

-- Query to retrieve user registered after a certain date
SELECT * FROM Users WHERE RegistrationTimestamp > [Date];

-- Query to retrive active users
SELECT * FROM Users WHERE LastLoginTimestamp < [Date];

-- Query to retrieve users by name
SELECT * FROM Users WHERE FirstName = 'John' AND LastName = 'Doe';

-- Query to retrieve users by area code
SELECT * FROM Users WHERE MobileNumber LIKE '123%';

-- Query to retrive the number of users
SELECT COUNT(*) AS UserCount FROM Users;

-- Query to retrive users and their respective addresses
SELECT Users.*, Addresses.*
FROM Users
LEFT JOIN Addresses ON Users.UserID = Addresses.UserID;

-- TRANSACTION QUERIES
-- Query to retrieve all transactions
SELECT * FROM Transactions;

-- Query to retreive transaction by transactionID
SELECT * FROM Transactions WHERE TransactionID = [TransactionID];

-- Query to retrieve transaction by user
SELECT * FROM Transactions WHERE UserID = [UserID];

-- Query to retrieve all items in a transaction
SELECT * FROM TransactionItems WHERE Discount > 0;

-- Query to retrieve transactions with a total higher than a certain amount
SELECT * FROM Transactions WHERE GrandTotal > [Amount];

-- Query to retrieve transactions with a specific order status
SELECT * FROM Transactions WHERE OrderStatus = 'Completed';

-- Query to retrieve transactions sorted by creation time
SELECT * FROM Transactions ORDER BY CreationTimestamp DESC;

-- Query to retrieve total sales revenue
SELECT SUM(GrandTotal) AS TotalSalesAmount FROM Transactions;

-- Query to retrieve total sales revenue and quantity for each item
SELECT ProductID, SUM(PurchasePrice * Quantity) AS TotalSalesAmount, SUM(Quantity) AS TotalQuantitySold
FROM TransactionItems
GROUP BY ProductID;

-- Query to calculate gross profit
SELECT 
    SUM(t.Subtotal) AS TotalSales,
    SUM(v.TotalPurchasedStockValue) AS TotalCost,
    SUM(t.Subtotal) - SUM(v.TotalPurchasedStockValue) AS GrossProfit
FROM Transactions t
CROSS JOIN (SELECT SUM(TotalPurchasedStockValue) AS TotalPurchasedStockValue FROM Vendors) v;

-- TRIGGERS
-- Quantity updates every time a product is registered into the transactionitems table
DELIMITER //

CREATE TRIGGER UpdateInventoryQuantity
AFTER INSERT ON TransactionItems
FOR EACH ROW
BEGIN
    DECLARE newQuantity INT;
    
    -- Get the new quantity from the inserted TransactionItem
    SELECT Quantity INTO newQuantity FROM TransactionItems WHERE TransItemID = NEW.TransItemID;
    
    -- Update the quantity in the Inventory table
    UPDATE Inventory
    SET QuantityInStock = QuantityInStock - newQuantity
    WHERE ProductID = NEW.ProductID;
END;
//

DELIMITER ;

-- Trigger to update audit trail for each change in inventory
DELIMITER //

CREATE TRIGGER AuditTrail_Inventory
AFTER INSERT ON Inventory
FOR EACH ROW
BEGIN
    INSERT INTO AuditTrail_Inventory (ActionType, UserID, Timestamp, OldValue, NewValue)
    VALUES ('INSERT', CURRENT_USER(), NOW(), NULL, CONCAT('ProductID: ', NEW.ProductID, ', CategoryID: ', NEW.CategoryID, ', BrandID: ', NEW.BrandID, ', SKU: ', NEW.SKU, '...'));
END;
//

DELIMITER ;
