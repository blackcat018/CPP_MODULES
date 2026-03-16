#include"MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    int i = 0;
    while(i < 4)
    {
        this->matter[i] = NULL;
        i++;
    }
}

MateriaSource::MateriaSource(const MateriaSource& cpy)
{
    int i = 0;
    while (i<4)
    {
        if(cpy.matter[i]){
            this->matter[i] = cpy.matter[i]->clone();
        }
        else
            this->matter[i] = NULL;
        i++;
    }
}
MateriaSource& MateriaSource::operator=(const MateriaSource& op)
{
    int i = 0;
    if(this !=&op)
    {
        while(i < 4)
        {
            if(this->matter[i])
            {
                delete matter[i];
                matter[i] = NULL;
            }
            i++;
        }
        i = 0;
        while(i < 4)
        {
            if(op.matter[i])
                this->matter[i] = op.matter[i]->clone();
            else
                this->matter[i] = NULL;
            i++;
        }
    }
    return(*this);
}

MateriaSource::~MateriaSource()
{
    int i = 0;
    while(i < 4)
    {
        if(this->matter[i])
            delete this->matter[i];
        i++;
    }
}

void MateriaSource::learnMateria(AMateria *mat)
{
    if(!mat)
        return;
    int i = 0;
    while(i < 4)
    {
        if(!this->matter[i])
        {
            this->matter[i] = mat;
            return;
        }
        i++;
    }
}
AMateria* MateriaSource::createMateria(std::string const & chemical)
{
    int i = 0;
    
    while (i < 4)
    {
        // std::cout << "comparing " << this->matter[i]->getType() << " with " << chemical << std::endl;
        if(this->matter[i] && this->matter[i]->getType() == chemical)
            return(this->matter[i]->clone());
        i++;
    }
    return NULL;
}