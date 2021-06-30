#include "graphnode.h"

GraphNode::GraphNode(int id) { _id = id; }

GraphNode::~GraphNode() {
  //// STUDENT CODE ////
  ////
  //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) { _answers.push_back(token); }

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
  _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge) {
  _childEdges.push_back(std::move(std::make_unique<GraphEdge>(*edge)));
}

//// STUDENT CODE ////
void GraphNode::MoveChatbotHere(ChatBot chat_bot) {
  _chatBot = std::move(chat_bot);
  _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  newNode->MoveChatbotHere(std::move(_chatBot));
}

GraphNode::GraphNode(GraphNode& other_node){
  _childEdges = std::move(other_node._childEdges);
  other_node._childEdges.clear();
  _parentEdges = other_node._parentEdges;
  // _chatBot = nullptr;
  _id = other_node._id;
  _answers = other_node._answers;
}

//// EOF STUDENT CODE ////

GraphEdge &GraphNode::GetChildEdgeAtIndex(int index) {
  //// STUDENT CODE
  ////

  return *_childEdges[index].get();

  ////
  //// EOF STUDENT CODE
}