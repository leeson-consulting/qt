#ifndef MEANDERAFFECTOR_H
#define MEANDERAFFECTOR_H
#include "particleaffector.h"

class MeanderAffector : public ParticleAffector
{
    Q_OBJECT
    //Like drift, but affects da/dt instead of ds/dt
    Q_PROPERTY(qreal xDrift READ xDrift WRITE setXDrift NOTIFY xDriftChanged)
    Q_PROPERTY(qreal yDrift READ yDrift WRITE setYDrift NOTIFY yDriftChanged)
public:
    explicit MeanderAffector(QObject *parent = 0);
    virtual bool affect(ParticleData *d, qreal dt);

    qreal xDrift() const
    {
        return m_xDrift;
    }

    qreal yDrift() const
    {
        return m_yDrift;
    }

signals:

    void xDriftChanged(qreal arg);

    void yDriftChanged(qreal arg);

public slots:

    void setXDrift(qreal arg)
    {
        if (m_xDrift != arg) {
            m_xDrift = arg;
            emit xDriftChanged(arg);
        }
    }
    void setYDrift(qreal arg)
    {
        if (m_yDrift != arg) {
            m_yDrift = arg;
            emit yDriftChanged(arg);
        }
    }

private:
    qreal m_xDrift;
    qreal m_yDrift;
};

#endif // MEANDERAFFECTOR_H