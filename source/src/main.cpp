#include <iostream>
#include <unordered_map>

#include "thread_pool.h"
#include "film.h"
#include "Mesh.h"
#include "ModelReader.h"

class SimpleTask : public Task{
    void run() override {
        std::cout << "test\n" << std::endl;
    }
};

int main() {
    std::unordered_map<std::string, Material*> materialMap;
    std::vector<Mesh> meshes;
    const std::string filename = R"(C:\Users\yyd\Desktop\test.obj)";

    ModelReader::readModelFile(filename, meshes, materialMap);
    std::cout << "mat " <<materialMap.size() << std::endl;
    std::cout << "mesh " << meshes.size() << std::endl;
    std::cout << "vex " << meshes[0].vertices.size() << std::endl;
    std::cout << "tri " << meshes[0].triangles.size() << std::endl;
    return 0;
}