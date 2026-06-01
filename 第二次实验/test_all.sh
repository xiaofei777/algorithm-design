#!/bin/bash

# 实验快速测试脚本

echo "========================================"
echo "      贪心算法实验 - 完整测试"
echo "========================================"
echo ""

# 检查可执行文件是否存在
if [ ! -f "gas_station" ]; then
    echo "正在编译程序..."
    gcc -o gas_station gas_station.c
    if [ $? -ne 0 ]; then
        echo "编译失败！"
        exit 1
    fi
    echo "编译成功！"
    echo ""
fi

# 测试数据1
echo "--- 测试数据1 (示例) ---"
echo "输入文件: input.txt"
cat input.txt
echo "运行结果:"
./gas_station input.txt
echo ""

# 测试数据2
echo "--- 测试数据2 ---"
echo "输入文件: input2.txt"
cat input2.txt
echo "运行结果:"
./gas_station input2.txt
echo ""

# 测试数据3
echo "--- 测试数据3 ---"
echo "输入文件: input3.txt"
cat input3.txt
echo "运行结果:"
./gas_station input3.txt
echo ""

# 测试数据4
echo "--- 测试数据4 (无法到达) ---"
echo "输入文件: input4.txt"
cat input4.txt
echo "运行结果:"
./gas_station input4.txt
echo ""

echo "========================================"
echo "      所有测试完成！"
echo "========================================"
