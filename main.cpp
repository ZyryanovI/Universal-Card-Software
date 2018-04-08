#include <iostream>
#include <gtest/gtest.h>
#include "CBankCardReader.h"
#include "CInsurancePolicyReader.h"
#include "CInternationalPassportReader.h"
#include "CPasportReader.h"

TEST(PrjTest, TestCCard)
{
    std::string name = "Petrov Petr Petrovich";
    unsigned long long int id = 12345678;
    std::string end_date = "14.06.2020";
    CCard card2(id, name, end_date);
    std::shared_ptr<CCard> card = std::make_shared(&card2);

    card->Get_Info();
    EXPECT_EQ(card->Get_Name(), "Petrov Petr Petrovich");
    EXPECT_EQ(card->Get_Id(), 12345678);
    EXPECT_EQ(card->Get_End(), "14.06.2020");
    EXPECT_EQ(2, 2);
}

TEST(PrjTest, TestCPasportReaderAndCInternationalPassportReader)
{
    std::string name = "Petrov Petr Petrovich";
    unsigned long long int id = 12345678;
    std::string end_date = "14.06.2020";
    std::shared_ptr<CCard> card = new CCard(id, name, end_date);
    CPasportReader reader;
    reader.Read(card);
    reader.Show_Info();
    CInternationalPasportReader reader2;
    reader2.Read(card);
    reader2.Show_Info();
    EXPECT_EQ(2, 2);
}

TEST(PrjTest, TestCBankCardReader)
{
    std::string name = "Petrov Petr Petrovich";
    unsigned long long int id = 12345678;
    std::string end_date = "14.06.2020";
    std::shared_ptr<CCard> card = new CCard(id, name, end_date);
    CBankReader reader;
    reader.Read(card);
    reader.Put_Money(30);
    reader.Transfer_To_Another_Card(12345654, 5);
    reader.Put_Money_To_Phone("+79221594783", 5);
    EXPECT_EQ(reader.Put_Money(20), true);
    EXPECT_EQ(reader.Withdraw_Money(60), false);
    EXPECT_EQ(reader.Withdraw_Money(10), true);

}

TEST(PrjTest, TestCInsurancePolicyReader)
{
    std::string name = "Petrov Petr Petrovich";
    unsigned long long int id = 12345678;
    std::string end_date = "14.06.2020";
    std::shared_ptr<CCard> card = new CCard(id, name, end_date);
    CInsurancePolicyReader reader;
    reader.Read(card);
    reader.Add_Situation("broken leg", 3000, 100);
    reader.Add_Situation("broken arm", 1500, 50);
    reader.Show_Info();
    reader.Remove_Situation("broken arm", 1500, 50);
    EXPECT_EQ(2, 2);
}




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
