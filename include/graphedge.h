#ifndef GRAPHEDGE_H_
#define GRAPHEDGE_H_

#include <string>
#include <vector>

#include "graphnode.h"

class GraphNode;

class GraphEdge {
  private:
    // data handles (not owned)
    GraphNode *_childNode;
    GraphNode *_parentNode;

    // proprietary members
    int _id;
    // list of topics associated with this edge
    std::vector<std::string> _keywords; 

  public:
    // constructor / desctructor
    GraphEdge(int id);
    ~GraphEdge(){};
    
    // getter / setter
    int GetID() { return _id; }
    void SetChildNode(GraphNode *childNode);
    void SetParentNode(GraphNode *parentNode);
    GraphNode *GetChildNode() { return _childNode; }
    std::vector<std::string> GetKeywords() { return _keywords; }

    // proprietary functions
    void AddToken(std::string token);
};

#endif /* GRAPHEDGE_H_ */