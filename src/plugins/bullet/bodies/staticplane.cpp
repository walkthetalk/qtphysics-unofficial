#include "staticplane.h"

namespace Physics {

namespace Bullet {

StaticPlane::StaticPlane(QObject* parent):
    AbstractBody(parent),
    m_normal(0,1,0),
    m_planeConstant(0.0f)
{
    setMass(0.0f);
    initShape();
    initBody();
}

StaticPlane::~StaticPlane()
{

}

void StaticPlane::setPlaneConstant(qreal d){
    if(m_planeConstant!=d){
        m_planeConstant=d;      
        delete m_shape;
        m_shape = new btStaticPlaneShape(btVector3(m_normal.x(),m_normal.y(),m_normal.z()), m_planeConstant);
        m_rigidBody->setCollisionShape(m_shape);
        setMassProps();
    }
}

void StaticPlane::setNormal(QVector3D normal){
    if(m_normal!=normal){
        m_normal=normal;
        delete m_shape;
        m_shape = new btStaticPlaneShape(btVector3(m_normal.x(),m_normal.y(),m_normal.z()), m_planeConstant);
        m_rigidBody->setCollisionShape(m_shape);
        setMassProps();
    }
}
void StaticPlane::setMass(qreal mass){
    if(m_mass!=mass){
        qWarning()<<"StaticPlane does not support mass";
    }
}

void StaticPlane::initShape(){
    m_shape = new btStaticPlaneShape(btVector3(m_normal.x(),m_normal.y(),m_normal.z()), m_planeConstant);
}

}}
