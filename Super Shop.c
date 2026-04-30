#include <stdio.h>

int main() {
    float total = 0, tax, discount = 0, finalTotal, donation = 0;
    char more, customerType, seasonalOffer, donate;
    int points = 0, code, quantity;

    float customerDiscount = 0;
    float seasonalDiscount = 0;

    int productSold[31] = {0};

    float prices[31] = {
        0, 80, 150, 30, 10, 70, 50, 90, 25, 100, 90,
        150, 200, 30, 25, 12, 50, 200, 150, 100, 35,
        60, 120, 40, 70, 55, 20, 110, 85, 75, 45
    };

    const char *productNames[31] = {
        "", "Rice (1 kg)", "Oil (1 L)", "Soap (1 pc)", "Pen (1 pc)", "Sugar (1 kg)", "Salt (1 kg)", "Milk (1 L)", "Biscuit (1 pkt)", "Shampoo (200 ml)", "Toothpaste (150 g)",
        "Tea (200 g)", "Coffee (100 g)", "Chips (1 pkt)", "Noodles (1 pkt)", "Egg (1 pc)", "Bread (1 loaf)", "Butter (500 g)", "Cheese (500 g)", "Detergent (1 kg)", "Tissue (1 pack)",
        "Flour (1 kg)", "Hand Sanitizer (100 ml)", "Face Mask (1 pc)", "Candle (1 pc)", "Juice (1 bottle)", "Notebook (1 pc)", "Cleaner (1 bottle)", "Hair Oil (100 ml)", "Chocolate (1 bar)", "Mug (1 pc)"
    };

    printf("==========================================\n");
    printf("         Welcome to General Shop          \n");
    printf("==========================================\n");
    printf("Hey there! We are really glad you are here.\n");
    printf("No matter how your day has been so far,\n");
    printf("we hope this little shopping trip brings you\nsome ease and a reason to smile.\n");
    printf("------------------------------------------\n");

    printf("\nAre you a (N)ewcomer or an (O)ld customer with store card? (N/O): ");
    scanf(" %c", &customerType);

    printf("Is there a seasonal offer today? (E.g., Eid/Pohela Boishakh) (y/n): ");
    scanf(" %c", &seasonalOffer);

    do {
        printf("\nProduct List:\n");
        for (int i = 1; i <= 30; i++) {
            printf("%2d. %-25s - %.2f TK\n", i, productNames[i], prices[i]);
        }

        printf("\nEnter product code (1-30): ");
        scanf("%d", &code);
        if (code < 1 || code > 30) {
            printf("Invalid product code! Please try again.\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        total += prices[code] * quantity;
        productSold[code] += quantity;

        printf("Add more products? (y/n): ");
        scanf(" %c", &more);

    } while (more == 'y' || more == 'Y');

    if (seasonalOffer == 'y' || seasonalOffer == 'Y') {
        seasonalDiscount = total * 0.07;
        discount += seasonalDiscount;
    }

    if (customerType == 'N' || customerType == 'n') {
        customerDiscount = total * 0.10;
        discount += customerDiscount;
    } else if (customerType == 'O' || customerType == 'o') {
        customerDiscount = total * 0.05;
        discount += customerDiscount;
        points = (int)(total / 100);
    }

    tax = (total - discount) * 0.05;

    printf("Would you like to donate to the people of Palestine? (y/n): ");
    scanf(" %c", &donate);
    if (donate == 'y' || donate == 'Y') {
        printf("Enter donation amount (TK): ");
        scanf("%f", &donation);
    }

    finalTotal = total - discount + tax + donation;

    printf("\n===============================\n");
    printf("        DISCOUNT SUMMARY       \n");
    printf("===============================\n");
    if (customerType == 'N' || customerType == 'n') {
        printf("New Customer: You received a 10%% discount.\n");
    } else if (customerType == 'O' || customerType == 'o') {
        printf("Loyal Customer: You received a 5%% discount.\n");
    }
    if (seasonalOffer == 'y' || seasonalOffer == 'Y') {
        printf("Seasonal Offer: You received a 7%% discount.\n");
    }
    if (discount == 0) {
        printf("No discounts applied today.\n");
    }

    printf("\n===============================\n");
    printf("            FINAL BILL         \n");
    printf("===============================\n");
    printf("Subtotal:                 %.2f TK\n", total);
    if (customerDiscount > 0)
        printf("Customer Discount:        -%.2f TK\n", customerDiscount);
    if (seasonalDiscount > 0)
        printf("Seasonal Discount:        -%.2f TK\n", seasonalDiscount);
    printf("Total Discount:           -%.2f TK\n", discount);
    printf("Tax (5%%):                  +%.2f TK\n", tax);
    printf("Donation:                 +%.2f TK\n", donation);
    printf("-------------------------------\n");
    printf("Total Payable:             %.2f TK\n", finalTotal);
    if (points > 0)
        printf("Loyalty Points Earned:     %d\n", points);

    if (donation > 0) {
        printf("\nThank you for your generous donation.\n");
        printf("Your kindness will help the people of Palestine.\n");
    } else {
        printf("\nThank you for your purchase!\n");
        printf("Every visit matters. Consider donating next time.\n");
    }

    printf("\n===============================\n");
    printf("         SALES SUMMARY         \n");
    printf("===============================\n");
    printf("Product Name               | Quantity Sold\n");
    printf("---------------------------|----------------\n");
    for (int i = 1; i <= 30; i++) {
        if (productSold[i] > 0)
            printf("%-27s %6d\n", productNames[i], productSold[i]);
    }

    // Rating system
    char rateChoice;
    int rating;

    printf("\nWould you like to rate your experience at our shop? (y/n): ");
    scanf(" %c", &rateChoice);

    if (rateChoice == 'y' || rateChoice == 'Y') {
        printf("Please rate us from 0 to 5 stars: ");
        scanf("%d", &rating);

        printf("\n===============================\n");
        printf("         CUSTOMER RATING       \n");
        printf("===============================\n");

        switch (rating) {
            case 5:
                printf("Thank you so much for the 5-star rating!\n");
                printf("We're thrilled that you had an excellent experience.\n");
                printf("Your support means a lot to us. Hope to see you again soon!\n");
                break;
            case 4:
                printf("Thank you for the great 4-star rating!\n");
                printf("We're glad you had a good experience and we will keep improving.\n");
                break;
            case 3:
                printf("Thank you for the 3-star rating.\n");
                printf("We appreciate your feedback and look forward to making your next visit better.\n");
                break;
            case 2:
                printf("Thanks for the 2-star rating.\n");
                printf("We're sorry it wasn't the best. We'll try to improve with your feedback.\n");
                break;
            case 1:
                printf("Thank you for your honesty.\n");
                printf("We're taking your input seriously and will strive to do better.\n");
                break;
            case 0:
                printf("We're really sorry that your experience wasn't good.\n");
                printf("Thank you for being honest. Your feedback helps us grow.\n");
                printf("We hope to earn your trust next time.\n");
                break;
            default:
                printf("Invalid rating. Please enter a number between 0 and 5.\n");
                break;
        }
    } else {
        printf("\nNo problem! We're happy to serve you anytime.\n");
    }

    printf("\nThank you again for shopping with us!\n");
    printf("Have a wonderful day!\n");
    printf("======================================\n");

    return 0;
}
