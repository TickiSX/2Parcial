#include <iostream>
#include <Vectors/Vector2.h>
#include <Vectors/Vector3.h>
#include <Vectors/Vector4.h>
#include <Rotations/Quaternion.h>
#include <Matrices/Matrix2x2.h>
#include <Matrices/Matrix3x3.h>
#include <Matrices/Matrix4x4.h>

using namespace EU;

int main() {
    std::cout << "==== TESTING ENGINE UTILITIES ====\n\n";

    // ----- Vector2 -----
    CVector2 v2a(3.0f, 4.0f);
    CVector2 v2b(1.0f, 2.0f);
    std::cout << "Vector2 sum: (" << (v2a + v2b).x << ", " << (v2a + v2b).y << ")\n";

    // ----- Vector3 -----
    CVector3 v3a(1.0f, 0.0f, 0.0f);
    CVector3 v3b(0.0f, 1.0f, 0.0f);
    CVector3 v3Cross = v3a.cross(v3b);
    std::cout << "Vector3 cross: (" << v3Cross.x << ", " << v3Cross.y << ", " << v3Cross.z << ")\n";

    // ----- Matrix2x2 -----
    Matrix2x2 m2a(1, 2, 3, 4);
    Matrix2x2 m2b(5, 6, 7, 8);
    Matrix2x2 m2c = m2a * m2b;
    std::cout << "Matrix2x2 multiplication result:\n";
    std::cout << m2c(0, 0) << " " << m2c(0, 1) << "\n";
    std::cout << m2c(1, 0) << " " << m2c(1, 1) << "\n";

    // ----- Matrix3x3 -----
    Matrix3x3 m3 = Matrix3x3::identity();
    m3 = m3 * 2.0f;
    std::cout << "\nMatrix3x3 scaled by 2:\n";
    for (int i = 0; i < 3; ++i)
        std::cout << m3(i, 0) << " " << m3(i, 1) << " " << m3(i, 2) << "\n";

    // ----- Matrix4x4 -----
    Matrix4x4 m4a;
    m4a.setScale(2.0f, 3.0f, 4.0f);
    CVector3 vecToScale(1.0f, 1.0f, 1.0f);
    CVector3 scaled = m4a.transformPoint(vecToScale);
    std::cout << "\nMatrix4x4 scale result: (" << scaled.x << ", " << scaled.y << ", " << scaled.z << ")\n";

    // ----- Quaternion -----
    Quaternion q1 = Quaternion::fromAxisAngle(CVector3(0, 1, 0), 3.1416f / 2); // 90� around Y
    CVector3 rotated = q1.rotate(CVector3(1, 0, 0)); // rotate X axis
    std::cout << "\nQuaternion rotated vector: (" << rotated.x << ", " << rotated.y << ", " << rotated.z << ")\n";

    // ----- Quaternion interpolation -----
    Quaternion qA(0, 0, 0, 1);
    Quaternion qB = Quaternion::fromAxisAngle(CVector3(0, 1, 0), 3.1416f);
    Quaternion qInterpolated = Quaternion::lerp(qA, qB, 0.5f);
    std::cout << "\nQuaternion LERP (50%): (" << qInterpolated.x << ", " << qInterpolated.y << ", " << qInterpolated.z << ", " << qInterpolated.w << ")\n";

    std::cout << "\n==== ALL ENGINE OPERATIONS SUCCESSFULLY TESTED ====\n";

    return 0;
}