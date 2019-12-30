// Version: 2.0
// Author: Mohamad Chehadeh
// Date: 30 Dec 2019
//Revision Note: Added static operations on vectors
#pragma once 

#include <cstdint>
#include "CustomMath.hpp"
template <class T>  

class Vector3D
{
        public:
        
                T x = 0;
                T y = 0;
                T z = 0;

                Vector3D<T> operator + (Vector3D<T> obj)
                {
                        Vector3D<T> res;
                        res.x = x + obj.x;
                        res.y = y + obj.y;
                        res.z = z + obj.z;
                        return res;
                }
                Vector3D<T> operator - (Vector3D<T> obj)
                {
                        Vector3D<T> res;
                        res.x = x - obj.x;
                        res.y = y - obj.y;
                        res.z = z - obj.z;
                        return res;
                }
                Vector3D<T> operator * (Vector3D<T> obj)
                {
                        Vector3D<T> res;
                        res.x = x * obj.x;
                        res.y = y * obj.y;
                        res.z = z * obj.z;
                        return res;
                }
                Vector3D<T> operator * (T tmp)
                {
                        Vector3D<T> res;
                        res.x = this->x * tmp;
                        res.y = this->y * tmp;
                        res.z = this->z * tmp;
                        return res;
                }
                Vector3D<T> operator / (T tmp)
                {
                        Vector3D<T> res;
                        res.x = this->x / tmp;
                        res.y = this->y / tmp;
                        res.z = this->z / tmp;
                        return res;
                }
                void operator = (T tmp)
                {
                        this->x = tmp;
                        this->y = tmp;
                        this->z = tmp;
                }

                template <typename M>
                operator Vector3D<M>()
                {
                        Vector3D<M> tmp;
                        tmp.x = M(this->x);
                        tmp.y = M(this->y);
                        tmp.z = M(this->z);

                        return tmp;
                }

                static double getL2Norm(Vector3D<T> vec1,Vector3D<T> vec2){
                    Vector3D<T> diff_vec=vec2-vec1;
                    return CustomMath::Q_rsqrt((float)diff_vec.x*diff_vec.x+diff_vec.y*diff_vec.y+diff_vec.z*diff_vec.z);
                }
                static double getL2Norm(Vector3D<T> vec1){
                    return CustomMath::Q_rsqrt((float)vec1.x*vec1.x+vec1.y*vec1.y+vec1.z*vec1.z);
                }
                static Vector3D<T> normalize(Vector3D<T> vec1){
                    return vec1/getL2Norm(vec1);
                }

};