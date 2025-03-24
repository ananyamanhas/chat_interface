cmake_minimum_required(VERSION 3.5)
project(chat_interface)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(timothy_publisher src/timothy_publisher.cpp)
ament_target_dependencies(timothy_publisher rclcpp std_msgs)

add_executable(bob_subscriber src/bob_subscriber.cpp)
ament_target_dependencies(bob_subscriber rclcpp std_msgs)

install(TARGETS
  timothy_publisher
  bob_subscriber
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

