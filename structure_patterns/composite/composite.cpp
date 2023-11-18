#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;

//base class Component
class Component {
    protected:
        Component* parent;
    public:
        void setParent(Component *newParent)
        {
            this->parent = newParent;
        }
        
        Component* getParentInstance()
        {
            return this->parent;
        }

        virtual void addComponent(Component* newComponent) {};
        virtual void removeComponent(Component* componentToRemove) {};

        virtual bool isComposite() const
        {
            return false;
        }

        virtual string componentBehavior() const = 0;       
};

class Leaf : public Component {
    public:
        string componentBehavior() const override
        {
            return " Im a leaf ";
        }
};

class Composite : public Component {
    protected:
        list<Component*> compositeChildren;
    
    public:
        void addComponent(Component* newComponent) override
        {
            this->compositeChildren.push_back(newComponent);
            newComponent->setParent(this);
        };

        void removeComponent(Component* componentToRemove) override
        {
            this->compositeChildren.remove(componentToRemove);
            componentToRemove->setParent(nullptr);
        };

        bool isComposite() const override
        {
            return true;
        }

        string componentBehavior() const override
        {
            string result;
            for(const Component* child : compositeChildren)
            {
                if (child == compositeChildren.back()) {
                    result += child->componentBehavior();                
                }else {
                    result += child->componentBehavior() + " + ";            
                }
            }            
            return "Total result( " + result + " )";        
        };
};

string Client(Component* component)
{
    return "=> " + component->componentBehavior();
} 

string ClientTwo(Component* component1, Component* component2)
{
    if (component1->isComposite()) {
        component1->addComponent(component2);
    }
    return "=> " + component1->componentBehavior();
}

int main () {
    cout << "Client working with a leaf\n";   
    Component* simpleLeaf = new Leaf();
    cout << Client(simpleLeaf) << "\n";
    
    cout << "I am going to create a tree\n";
    Component* tree = new Composite();
    Component* nodeOne = new Composite();
    Component* nodeTwo = new Composite();
    
    Component* simpleLeaf1 = new Leaf();
    Component* simpleLeaf2 = new Leaf();
    Component* simpleLeaf3 = new Leaf();
    
    nodeOne->addComponent(simpleLeaf1);
    nodeOne->addComponent(simpleLeaf2);
    
    nodeTwo->addComponent(simpleLeaf3);
    
    tree->addComponent(nodeOne);
    tree->addComponent(nodeTwo);
    
    cout << "Client result in the Tree\n";
    cout << Client(tree) << '\n';    

    return 0;
}


