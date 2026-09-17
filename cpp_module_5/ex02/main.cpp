#include "Bureaucrat.hpp"
#include "Shrubbery.hpp"
#include "Robot.hpp"
#include "President.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Seed rand() for Robotomy's 50% chance check
    std::srand(std::time(NULL));

    std::cout << "========== CREATING BUREAUCRATS ==========" << std::endl;
    Bureaucrat boss("Zaphod", 1);       // Rank 1: Can do everything
    Bureaucrat manager("Arthur", 40);   // Rank 40: Can sign shrubbery & robotomy, execute shrubbery & robotomy
    Bureaucrat intern("Marvin", 140);   // Rank 140: Can only sign shrubbery

    std::cout << "\n========== CREATING FORMS ==========" << std::endl;
    shrubb    shrub("backyard");
    robot     bot("Wall-E");
    president pardon("Ford Prefect");

    std::cout << "\n========== TEST 1: EXECUTE UNSIGNED FORMS ==========" << std::endl;
    // Should fail because forms aren't signed yet
    boss.executeForm(shrub);
    boss.executeForm(bot);
    boss.executeForm(pardon);

    std::cout << "\n========== TEST 2: SIGNING FORMS ==========" << std::endl;
    intern.signForm(shrub);   // Success (140 <= 145)
    intern.signForm(bot);     // Fails (140 > 72)
    manager.signForm(bot);    // Success (40 <= 72)
    boss.signForm(pardon);   // Success (1 <= 25)

    std::cout << "\n========== TEST 3: GRADE TOO LOW TO EXECUTE ==========" << std::endl;
    // Marvin (140) signed the shrubbery, but can't execute it (requires 137)
    intern.executeForm(shrub);

    std::cout << "\n========== TEST 4: SUCCESSFUL EXECUTION ==========" << std::endl;
    // Arthur (40) executes Shrubbery (requires 137) and Robotomy (requires 45)
    manager.executeForm(shrub);
    manager.executeForm(bot);

    // Zaphod (1) executes Presidential Pardon (requires 5)
    boss.executeForm(pardon);

    return 0;
}