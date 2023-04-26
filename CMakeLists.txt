cmake_minimum_required(VERSION 3.23)
project(cppthing)

set(CMAKE_CXX_STANDARD 17)
# 指定头文件搜索路径
include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(lib)
include_directories("${PROJECT_SOURCE_DIR}/lib/googletest")
include_directories("${PROJECT_SOURCE_DIR}/lib/googletest/include")


add_executable(gtestDemo src/gtestDemo.cpp)
target_link_libraries(gtestDemo gtest gtest_main)

add_executable(cppthing main.cpp src/car.cpp src/iterator.cpp include/iterator.h src/iostream.cpp include/iostream.h include/all.h src/pionter.cpp src/move_constructor.cpp src/copy_constuctor.cpp src/smart_ptr.cpp src/ref_count.cpp src/weak_ptr.cpp)

add_executable(mymap STL/mymap.cpp)
add_executable(assert src/assert.cpp)
add_executable(poly src/poly.cpp)
add_executable(maohao src/maohao.cpp)
add_executable(define src/define.cpp)
add_executable(mystring STL/mystring.cpp)
add_executable(myvector STL/myvector.cpp)
add_executable(mystack STL/mystack.cpp)
add_executable(oj OJ/oj.cpp)

add_executable(template src/template.cpp)
add_executable(my_sort mylib/my_sort.cpp)
target_link_libraries(my_sort gtest gtest_main)
add_executable(test Test/test.cpp)
add_executable(salary src/salary.cpp)
add_executable(LRU Algorithm/LRU.cpp)
add_executable(LRUopt Algorithm/LRUopt.cpp)
add_executable(LRUnoListOpt Algorithm/LRUnoListOpt.cpp)
add_executable(override src/override.cpp)
add_executable(friend src/friend.cpp)
add_executable(constructor src/constructor.cpp)

add_executable(cast src/cast.cpp)
add_executable(trieTree Algorithm/trieTree.cpp)
add_executable(shortJobFirst Algorithm/shortJobFirst.cpp)
add_executable(trieTree_replaceWords Algorithm/trieTree_replaceWords.cpp)
add_executable(buildTree Algorithm/buildTree.cpp)
add_executable(mypriority_queue STL/mypriority_queue.cpp)
add_executable(simplefactory DesignPattern/SimpleFactory/simplefactory.cpp)
add_executable(singleton DesignPattern/Singleton/singleton.cpp)

add_executable(mythread STL/Concurrency/Thread/thread.cpp)
add_executable(lock_guard STL/Concurrency/Lock_guard/lock_guard.cpp)
add_executable(destruct src/destruct.cpp)
add_executable(unique_lock STL/Concurrency/Lock_guard/unique_lock.cpp)
add_executable(mutex STL/Concurrency/Mutex/mutex.cpp)
add_executable(rightquete src/rightquete.cpp)
add_executable(lambda src/lambda.cpp)
add_executable(factory DesignPattern/FactoryMethod/factorymethod.cpp DesignPattern/FactoryMethod/car.h DesignPattern/FactoryMethod/factory.h DesignPattern/FactoryMethod/bmw.h DesignPattern/FactoryMethod/bmwfactory.h DesignPattern/FactoryMethod/audi.h DesignPattern/FactoryMethod/audifatory.h)
add_executable(abstractfactory DesignPattern/AbstractFactory/abstractfactory.cpp)
add_executable(my_heapsort mylib/my_heapsort.cpp)
add_executable(quicksort STL/Sort/quicksort.cpp)
add_executable(isLittleEndian Csapp/isLittleEndian.cpp)
add_executable(virtual_func src/virtual_func.cpp)
add_executable(func_point src/func_point.cpp)
add_executable(number_limits OJ/number_limits.cpp)
add_executable(string_input OJ/string_input.cpp)
add_executable(bag0_1 Algorithm/bag0_1.cpp)
add_executable(simplefactory1 DesignPattern/SimpleFactory/simplefactory1.cpp)

#自动添加到工程，显示如下
add_executable(yazi-json yazi-json/yazi.cpp yazi-json/json.h yazi-json/json.cpp yazi-json/paser.cpp yazi-json/paser.h)


#手动添加到工程的方法
file(GLOB JSONCPP_SOURCE_FILES
        yazi-json/jsoncpp/lib/*.h
        yazi-json/jsoncpp/lib/*.cpp
        )
add_executable(jsoncpp yazi-json/jsoncpp/jsoncpp.cpp ${JSONCPP_SOURCE_FILES})



file(GLOB CJSON_SOURCE_FILES
        yazi-json/cJSON/*.h
        yazi-json/cJSON/*.c
        yazi-json/cJSON/lib/*.c
        yazi-json/cJSON/lib/*.h
        )
add_executable(cjson yazi-json/cJSON/main.c ${CJSON_SOURCE_FILES})
add_executable(mystl_string STL/mystl_string.cpp)
add_executable(my_string STL/String/my_string.cpp STL/String/my_string.h)
add_executable(pionter src/pionter.cpp)

add_executable(productor_consumer STL/Concurrency/Mutex/productor_consumer.cpp)
add_executable(perfect_define src/perfect_define.cpp)
add_executable(param_passing src/param_passing.cpp)


#file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
#foreach(file ${files})
#    get_filename_component(name ${file} NAME)
#    add_executable(${name} ${file})
#endforeach()
add_executable(copy_move_constructor src/move_constructor.cpp)
add_executable(copy_constuctor src/copy_constuctor.cpp)
add_executable(smart_ptr src/smart_ptr.cpp)
add_executable(ref_count src/ref_count.cpp)
add_executable(weak_ptr src/weak_ptr.cpp)
add_executable(thread_pool ThreadPool/thread_pool.cpp)
add_executable(mempool_c MemoryPool/mempool_c.cpp)
add_executable(inheritance src/inheritance.cpp)
add_executable(myAlgorithm myAlgorithm/myAlgorithm.cpp)
add_executable(dfs Algorithm/dfs.cpp)
add_executable(onlinetest myAlgorithm/onlinetest.cpp)
add_executable(o1 myAlgorithm/o1.cpp)
add_executable(o2 myAlgorithm/o2.cpp)
add_executable(o3 myAlgorithm/o3.cpp)
add_executable(o4 myAlgorithm/o4.cpp)
add_executable(o5 myAlgorithm/o5.cpp)
add_executable(o6 myAlgorithm/o6.cpp)
add_executable(o7 myAlgorithm/o7.cpp)
add_executable(o8 myAlgorithm/o8.cpp)
add_executable(mymultimap STL/mymultimap.cpp)