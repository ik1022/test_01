rm -Rf .build_test
cmake -S. -B.build_test -GNinja -DBUILD_FOR_UNIT_TESTS=ON
cmake --build .build_test --clean-first
ctest  --test-dir .build_test/
.build_test/tests/UnitTests -v